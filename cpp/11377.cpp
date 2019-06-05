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
        [&graph, &source, &drain, &capacity, &flow](vector<int>& level) -> bool {
            queue<int> queue;

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
    vector<int> level(num_node, -1), pivot(num_node, 0);
    while (get_level(level)) {
        while (int bf = get_flow(source, INF, pivot, level)) {
            net_flow += bf;
        }

        fill (level.begin(), level.end(), -1);
        fill (pivot.begin(), pivot.end(), 0);
    }

    return net_flow;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_worker, num_job, k;
    cin >> num_worker >> num_job >> k;

    const int source = 0;
    const int bridge = 1;
    const int drain = 2;

    function<int(int)> worker_to_node = [](int worker) -> int {
        return worker + 2;
    };

    function<int(int)> job_to_node = [&num_worker](int job) -> int {
        return num_worker + job + 2;
    };

    Graph graph(num_worker+num_job+3);

    graph.add_edge(source, bridge, k);

    for (int worker = 1; worker <= num_worker; ++worker) {
        graph.add_edge(source, worker_to_node(worker), 1);
        graph.add_edge(bridge, worker_to_node(worker), 1);
        graph.add_edge(worker_to_node(worker), bridge, 0);
    }

    for (int job = 1; job <= num_job; ++job) {
        graph.add_edge(job_to_node(job), drain, 1);
    }

    for (int worker = 1; worker <= num_worker; ++worker) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int job;
            cin >> job;
            graph.add_edge(worker_to_node(worker), job_to_node(job), 1);
            graph.add_edge(job_to_node(job), worker_to_node(worker), 0);
        }
    }

    cout << dinic(graph, source, drain) << endl;

    return EXIT_SUCCESS;
}

