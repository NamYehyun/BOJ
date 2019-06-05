#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


typedef vector<vector<int>> matrix_t;


class Graph {
public:
    int num_node;
    vector<vector<pair<int, int>>> edge;

    Graph(int _num_node): num_node(_num_node) {
        edge.resize(num_node, vector<pair<int, int>>());
    }

    void add_edge(int u, int v, int w) {
        edge[u].emplace_back(v, w);
        return;
    }
};


int dinic(Graph& graph, int source, int drain) {
    const int INF = 0x7f7f7f7f;
    const int num_node = graph.num_node;

    matrix_t capacity(num_node, vector<int>(num_node, 0));
    for (int u = 0; u < num_node; ++u) {
        for (auto edge: graph.edge[u]) {
            int v = edge.first;
            int w = edge.second;
            capacity[u][v] += w;
        }
    }

    matrix_t flow(num_node, vector<int>(num_node, 0));

    function<bool(vector<int>&)> get_level = 
        [&graph, &num_node, &source, &drain, &capacity, &flow](vector<int>& level) -> bool {
            queue<int> queue;

            level.resize(num_node, -1);
            
            level[source] = 0;
            queue.push(source);

            while (!queue.empty()) {
                int curr = queue.front(); queue.pop();
                for (auto const& edge: graph.edge[curr]) {
                    int next = edge.first;
                    if ((level[next] == -1) && (capacity[curr][next] > flow[curr][next])) {
                        level[next] = level[curr] + 1;
                        queue.push(next);
                    }
                }
        }

        return level[drain] != -1;
    };

    function<int(int, int, vector<int>&, vector<int>&)> get_flow = 
        [&get_flow, &graph, &drain, &capacity, &flow](int curr, int blocking_flow, vector<int>& pivot, vector<int>& level) -> int {
            if (curr == drain) {
                return blocking_flow;
            }

            int size = graph.edge[curr].size();
            for (int i = pivot[curr]; i < size; ++i) {
                int next = graph.edge[curr][i].first;
                if ((level[next] == level[curr] + 1) && (capacity[curr][next] > flow[curr][next])) {
                    int bf = get_flow(next, min(blocking_flow, capacity[curr][next] - flow[curr][next]), pivot, level);
                    if (bf > 0) {
                        flow[curr][next] += bf;
                        flow[next][curr] -= bf;

                        pivot[curr] = i;

                        return bf;
                    }
                }
            }

            pivot[curr] = size;

            return 0;
    };

    int net_flow = 0;
    vector<int> level;
    while (get_level(level)) {
        vector<int> pivot(num_node, 0);
        while (int bf = get_flow(source, INF, pivot, level)) {
            net_flow += bf;
        }

        level.clear();
    }

    return net_flow;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    function<int(char)> name_to_id = [](char name) -> int {
        return ('a' <= name && name <= 'z') ? static_cast<int>(name-'a') : static_cast<int>(name-'A'+26);
    };

    Graph graph(52);

    int num_edge;
    cin >> num_edge;
    for (int edge = 0; edge < num_edge; ++edge) {
        char name_u, name_v;
        int u, v, w;
        cin >> name_u >> name_v >> w;

        u = name_to_id(name_u);
        v = name_to_id(name_v);

        graph.add_edge(u, v, w);
        graph.add_edge(v, u, w);
    }

    cout << dinic(graph, name_to_id('A'), name_to_id('Z')) << endl;

    return EXIT_SUCCESS;
}

