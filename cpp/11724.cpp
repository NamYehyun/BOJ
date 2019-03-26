#include <iostream>
#include <vector>

using namespace std;


void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj_list) {
    visited[node] = true;
    for (int neighbor: adj_list[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj_list);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_node, num_edge;
    cin >> num_node >> num_edge;

    vector<vector<int>> adj_list(num_node+1, vector<int>());
    for (int edge = 0; edge < num_edge; ++edge) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int cnt = 0;
    vector<bool> visited(num_node+1, false);
    for (int node = 1; node <= num_node; ++node) {
        if (!visited[node]) {
            ++cnt;
            dfs(node, visited, adj_list);
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

