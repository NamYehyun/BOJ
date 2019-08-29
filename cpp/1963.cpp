#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0x3f7f7f7f;


bool adjacent(int a, int b) {
    int cnt = 0;

    const vector<int> _a {
        (a / 1000) % 10, (a / 100) % 10, (a / 10) % 10, a % 10
    };

    const vector<int> _b {
        (b / 1000) % 10, (b / 100) % 10, (b / 10) % 10, b % 10
    };


    for (int i = 0; i < 4; ++i) {
        if (_a[i] == _b[i]) {
            ++cnt;
        }
    }

    return (cnt >= 3);
}


int bfs(const int root, const int dest, vector<vector<int>>& adj) {
    const int num_node = adj.size();
    vector<int> dist(num_node, INF);

    queue<int> q;

    q.push(root);
    dist[root] = 0;

    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (const int& next: adj[curr]) {
            if (dist[next] < INF) {
                continue;
            }

            q.push(next);
            dist[next] = dist[curr] + 1;
        }

        if (dist[dest] < INF) {
            return dist[dest];
        }
    }

    return INF;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<bool> is_prime(10000, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 10000; ++i) {
        if (!is_prime[i]) {
            continue;
        }

        int m = 2;
        while (i*m < 10000) {
            is_prime[i*m] = false;
            ++m;
        }
    }

    int id = 0;
    vector<int> id_to_val;
    map<int, int> val_to_id;
    for (int i = 1000; i < 10000; ++i) {
        if (is_prime[i]) {
            id_to_val.emplace_back(i);
            val_to_id[i] = id;
            ++id;
        }
    }

    const int num_node = id_to_val.size();
    vector<vector<int>> adj(num_node, vector<int>());
    for (int i = 0; i < num_node; ++i) {
        for (int j = i+1; j < num_node; ++j) {
            if (i != j && adjacent(id_to_val[i], id_to_val[j])) {
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
        }
    }

    int num_query;
    cin >> num_query;
    while (num_query--) {
        int a, b;
        cin >> a >> b;

        a = val_to_id[a];
        b = val_to_id[b];

        int d = bfs(a, b, adj);
        if (d < INF) {
            cout << d << '\n';
        } else {
            cout << "Impossible" << '\n';
        }
    }

    return EXIT_SUCCESS;
}

