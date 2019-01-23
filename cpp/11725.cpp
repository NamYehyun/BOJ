#include <iostream>
#include <vector>

using namespace std;


void traverse(int curr, vector<vector<int>>& adjacency_list, vector<bool>& visited, vector<int>& parent_of) {
    visited[curr] = true;

    for (auto next: adjacency_list[curr]) {
        if (!visited[next]) {
            parent_of[next] = curr;
            traverse(next, adjacency_list, visited, parent_of);
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adjacency_list(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent_of(n + 1);

    traverse(1, adjacency_list, visited, parent_of);

    for (int node = 2; node <= n; ++node) {
        cout << parent_of[node] << '\n';
    }

    return EXIT_SUCCESS;
}

