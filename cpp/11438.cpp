#include <iostream>
#include <vector>

using namespace std;


class Tree {
public:
    const int max_exp = 20;

    int root;
    int num_node;
    vector<vector<int>> adj_list;
    vector<int> depth;
    vector<vector<int>> ancestor_pow2;

    Tree(int _root, int _num_node): root(_root), num_node(_num_node) {
        adj_list.resize(num_node+1, vector<int>());
        depth.resize(num_node+1, 0);
        ancestor_pow2.resize(num_node+1, vector<int>(max_exp+1, 0));
    }

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
        return;
    }

    void set_parent(int curr, int curr_depth, vector<bool>& visited) {
        visited[curr] = true;
        depth[curr] = curr_depth;

        for (int next: adj_list[curr]) {
            if (!visited[next]) {
                ancestor_pow2[next][0] = curr;
                set_parent(next, curr_depth+1, visited);
            }
        }

        return;
    }

    void preprocess(void) {
        vector<bool> visited(num_node+1, false);
        set_parent(root, 0, visited);

        for (int exp = 1; exp <= max_exp; ++exp) {
            for (int node = 1; node <= num_node; ++node) {
                ancestor_pow2[node][exp] = ancestor_pow2[ancestor_pow2[node][exp-1]][exp-1];
            }
        }

        return;
    }

    int lca(int n1, int n2) {
        if (depth[n1] > depth[n2]) {
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }

        for (int exp = max_exp; exp >= 0; --exp) {
            if (depth[n2] - depth[n1] >= (1 << exp)) {
                n2 = ancestor_pow2[n2][exp];
            }
        }

        if (n1 == n2) {
            return n1;
        }

        for (int exp = max_exp; exp >= 0; --exp) {
            if (ancestor_pow2[n1][exp] != ancestor_pow2[n2][exp]) {
                n1 = ancestor_pow2[n1][exp];
                n2 = ancestor_pow2[n2][exp];
            }
        }

        return ancestor_pow2[n1][0];
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    Tree t(1, n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        t.add_edge(u, v);
    }

    t.preprocess();

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        cout << t.lca(u, v) << '\n';
    }

    return EXIT_SUCCESS;
}

