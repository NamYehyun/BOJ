#include <iostream>
#include <vector>

using namespace std;


const long long DIV = 1000000007;


class Edge {
public:
    int to;
    long long weight;

    Edge(int _to, long long _weight) {
        to = _to;
        weight = _weight;
    }
};


long long weight_of_tree(int root, vector<vector<Edge>>& adj_list, vector<bool>& visited, long long& ans) {
    visited[root] = true;

    long long acc = 0;
    for (auto edge: adj_list[root]) {
        if (visited[edge.to]) {
            continue;
        }

        /* net weight of paths from nodes of a subtree to the root */
        long long sub = (weight_of_tree(edge.to, adj_list, visited, ans) + 1) * edge.weight % DIV;

        ans = (ans + sub * (acc + 1)) % DIV;
        acc = (acc + sub) % DIV;
    }

    return acc;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<Edge>> adj_list(n+1, vector<Edge>());
    for (int i = 0; i < n-1; ++i) {
        int x, y, weight;
        cin >> x >> y >> weight;

        adj_list[x].push_back(Edge(y, weight));
        adj_list[y].push_back(Edge(x, weight));
    }

    vector<bool> visited(n+1, false);

    long long ans = 0;
    weight_of_tree(1, adj_list, visited, ans);

    cout << ans << endl;

    return EXIT_SUCCESS;
}

