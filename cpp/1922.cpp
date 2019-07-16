#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Graph {
public:
    int num_node;
    vector<vector<pair<int, int>>> edges;

    Graph(int _num_node): num_node(_num_node) {
        edges.resize(num_node, vector<pair<int, int>>());
    }

    void add_edge(int u, int v, int w) {
        edges[u].emplace_back(v, w);
    }
};


int prim(Graph& graph) {
    vector<bool> visited(graph.num_node, false);

    visited[0] = true;
    int visit_count = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    for (const auto& edge: graph.edges[0]) {
        queue.push(make_pair(edge.second, edge.first));
    }

    int net_weight = 0;
    while (!queue.empty()) {
        auto item = queue.top(); queue.pop();
        int weight = item.first;
        int node = item.second;

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        ++visit_count;

        net_weight += weight;

        for (const auto& edge: graph.edges[node]) {
            if (!visited[edge.first]) {
                queue.push(make_pair(edge.second, edge.first));
            }
        }
    }

    return net_weight;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_node, num_edge;
    cin >> num_node >> num_edge;

    Graph graph(num_node);
    for (int i = 0; i < num_edge; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        graph.add_edge(u-1, v-1, w);
        graph.add_edge(v-1, u-1, w);
    }

    cout << prim(graph) << endl;

    return EXIT_SUCCESS;
}

