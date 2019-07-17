#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Graph {
public:
    int num_node;
    vector<vector<pair<int, int>>> adj_list;

    Graph(int _num_node): num_node(_num_node) {
        adj_list.resize(num_node, vector<pair<int, int>>());
    }

    void add_edge(int u, int v, int w) {
        adj_list[u].emplace_back(v, w);
    }
};


void floyd_warshall(Graph& graph, vector<vector<int>>& dist) {
    const int INF = 0x0f7f7f7f;
    const int num_node = graph.num_node;

    dist.resize(num_node, vector<int>(num_node, INF));

    for (int u = 0; u < num_node; ++u) {
        for (const auto& edge: graph.adj_list[u]) {
            dist[u][edge.first] = edge.second;
        }
        dist[u][u] = 0;
    }

    for (int k = 0; k < num_node; ++k) {
        for (int i = 0; i < num_node; ++i) {
            for (int j = 0; j < num_node; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_node, num_edge;
    cin >> num_node >> num_edge;

    Graph graph(num_node);
    for (int edge = 0; edge < num_edge; ++edge) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u-1, v-1, 1);
        graph.add_edge(v-1, u-1, 1);
    }

    vector<vector<int>> dist;
    floyd_warshall(graph, dist);

    int ans = -1;
    int min_acc = 0x7f7f7f7f;
    for (int u = 0; u < num_node; ++u) {
        int acc = 0;
        for (int v = 0; v < num_node; ++v) {
            acc += dist[u][v];
        } 

        if (min_acc > acc) {
            min_acc = acc;
            ans = u + 1;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

