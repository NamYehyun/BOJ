#include <iostream>
#include <vector>

using namespace std;


void dfs(int curr, vector<vector<bool>>& adj_matrix, vector<bool>& visited) {
    int size = visited.size();
    for (int next = 0; next < size; ++next) {
        if (!visited[next] && adj_matrix[curr][next]) {
            visited[next] = true;
            dfs(next, adj_matrix, visited);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            int flag;
            cin >> flag;
            adj_matrix[row][col] = (flag == 1);
        }
    }

    vector<vector<bool>> connected;
    for (int root = 0; root < n; ++root) {
        vector<bool> visited(n, false);
        dfs(root, adj_matrix, visited);

        connected.push_back(visited);
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            cout << connected[row][col] << ' ';
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

