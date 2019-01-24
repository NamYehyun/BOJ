#include <iostream>
#include <vector>

using namespace std;


void dfs(int node, vector<int>& pi, vector<bool>& visited) {
    visited[node] = true;

    if (!visited[pi[node]]) {
        dfs(pi[node], pi, visited);
    }

    return;
}


int num_cycles(int n, vector<int>& pi) {
    vector<bool> visited(n+1, false);

    int cnt = 0;
    for (int node = 1; node <= n; ++node) {
        if (!visited[node]) {
            dfs(node, pi, visited);
            ++cnt;
        }
    }

    return cnt;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> pi(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            pi[i] = x;
        }

        cout << num_cycles(n, pi) << '\n';
    }

    return EXIT_SUCCESS;
}

