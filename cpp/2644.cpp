#include <iostream>
#include <vector>

using namespace std;


int dist(int curr, int dst, vector<vector<int>>& adj_list, vector<bool>& visited) {
    visited[curr] = true;

    if (curr == dst) {
        return 0;
    }

    for (const int& next: adj_list[curr]) {
        if (visited[next]) {
            continue;
        }

        int d = dist(next, dst, adj_list, visited);
        if (d != -1) {
            return d + 1;
        }
    }

    return -1;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_node;
    cin >> num_node;
    
    int src, dst;
    cin >> src >> dst;

    int num_edge;
    cin >> num_edge;

    vector<vector<int>> adj_list(num_node+1, vector<int>());
    for (int edge = 0; edge < num_edge; ++edge) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<bool> visited(num_node+1, false);
    cout << dist(src, dst, adj_list, visited) << endl;

    return EXIT_SUCCESS;
}

