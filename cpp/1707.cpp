#include <iostream>
#include <vector>

using namespace std;


class Graph {
private:
    const int NIL = 0;
    const int WHITE = 1;
    const int BLACK = 2;

public:
    int num_node;
    int num_edge;
    vector<vector<int>> adj_list;

    Graph(int _num_node, int _num_edge): num_node(_num_node), num_edge(_num_edge) {
        adj_list.resize(num_node, vector<int>());
    }

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        return;
    }

    bool dfs(int curr, int colour, vector<int>& coloured) {
        coloured[curr] = colour;
        for (const int& next: adj_list[curr]) {
            if (coloured[next] == colour) {
                return false;
            } else if (!coloured[next] && !dfs(next, 3-colour, coloured)) {
                return false;
            }
        }

        return true;
    }

    bool is_bipartite(void) {
        vector<int> coloured(num_node, NIL);
        for (int node = 0; node < num_node; ++node) {
            if (!coloured[node] && !dfs(node, WHITE, coloured)) {
                return false;
            }
        }

        return true;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int num_node, num_edge;
        cin >> num_node >> num_edge;

        Graph graph(num_node, num_edge);
        for (int i = 0; i < num_edge; ++i) {
            int u, v;
            cin >> u >> v;
            graph.add_edge(u-1, v-1);
            graph.add_edge(v-1, u-1);
        }

        cout << (graph.is_bipartite() ? "YES" : "NO") << endl;        
    }

    return EXIT_SUCCESS;
}

