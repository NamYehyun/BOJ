#include <iostream>
#include <vector>

using namespace std;


int dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited) {
    visited[node] = true;

    int acc = 1;
    for (int neighbor: adj_list[node]) {
        if (!visited[neighbor]) {
            acc += dfs(neighbor, adj_list, visited);
        }        
    }

    return acc;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    vector<vector<int>> adj_list(num_nodes+1, vector<int>());
    for (int i = 0; i < num_edges; ++i) {
        int x, y;
        cin >> x >> y;

        adj_list[y].push_back(x);
    }

    int count_max = 0;
    vector<int> count(num_nodes+1, 0);
    for (int node = 1; node <= num_nodes; ++node) {
        vector<bool> visited(num_nodes+1, false);
        count[node] = dfs(node, adj_list, visited);

        if (count_max < count[node]) {
            count_max = count[node];
        }
    }

    for (int node = 1; node <= num_nodes; ++node) {
        if (count[node] == count_max) {
            cout << node << ' ';
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

