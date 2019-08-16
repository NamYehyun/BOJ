#include <iostream>
#include <tuple>
#include <vector>

using namespace std;


class Tree {
public:
    int num_node;
    vector<vector<int>> adj_list;

    Tree(int _num_node): num_node(_num_node) {
        adj_list.resize(num_node, vector<int>());
    }

    void add_edge(int u, int v) {
        adj_list[u].emplace_back(v);
        adj_list[v].emplace_back(u);
    }

    int path_decomposition(int k) {
        return dfs(0, -1, k).second;
    }

    pair<int, int> dfs(int curr, int prev, const int k) {
        int acc = 0;

        int c1 = 0;
        int c2 = 0;
        for (const auto& next: adj_list[curr]) {
            if (next == prev) {
                continue;
            }

            int c, a;
            tie(c, a) = dfs(next, curr, k);

            acc += a;

            if (c1 < c) {
                c2 = c1;
                c1 = c;
            } else if (c2 < c) {
                c2 = c;
            }
        }

        if (k + 1 < c1 + c2) {
            return {0, acc-1};
        }
        
        if (0 < c1) {
            return {c1-1, acc};
        }

        return {k, acc+1};
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Tree tree(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u-1, v-1);
    }

    cout << tree.path_decomposition(k) << endl;

    return EXIT_SUCCESS;
}

