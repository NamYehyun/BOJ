#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


typedef vector<vector<int>> matrix_t;


class Graph {
public:
    int num_node;
    vector<vector<pair<int, int>>> edge;

    Graph(int _num_node): num_node(_num_node) {
        edge.resize(num_node, vector<pair<int, int>>());
    }

    void add_edge(int u, int v, int w) {
        edge[u].emplace_back(v, w);
        return;
    }
};


int dinic(Graph& graph, int source, int drain) {
    const int INF = 0x7f7f7f7f;
    const int num_node = graph.num_node;

    matrix_t capacity(num_node, vector<int>(num_node, 0));
    for (int u = 0; u < num_node; ++u) {
        for (auto edge: graph.edge[u]) {
            int v = edge.first;
            int w = edge.second;
            capacity[u][v] += w;
        }
    }

    matrix_t flow(num_node, vector<int>(num_node, 0));

    function<bool(vector<int>&)> get_level = 
        [&graph, &source, &drain, &capacity, &flow](vector<int>& level) -> bool {
            queue<int> queue;

            level[source] = 0;
            queue.push(source);

            while (!queue.empty()) {
                int curr = queue.front(); queue.pop();
                for (auto const& edge: graph.edge[curr]) {
                    int next = edge.first;
                    if ((level[next] == -1) && (capacity[curr][next] > flow[curr][next])) {
                        level[next] = level[curr] + 1;
                        queue.push(next);
                    }
                }
            }

            return level[drain] != -1;
    };

    function<int(int, int, vector<int>&, vector<int>&)> get_flow = 
        [&get_flow, &graph, &drain, &capacity, &flow](int curr, int blocking_flow, vector<int>& pivot, vector<int>& level) -> int {
            if (curr == drain) {
                return blocking_flow;
            }

            int size = graph.edge[curr].size();
            for (int i = pivot[curr]; i < size; ++i) {
                int next = graph.edge[curr][i].first;
                if ((level[next] == level[curr] + 1) && (capacity[curr][next] > flow[curr][next])) {
                    int bf = get_flow(next, min(blocking_flow, capacity[curr][next] - flow[curr][next]), pivot, level);
                    if (bf > 0) {
                        flow[curr][next] += bf;
                        flow[next][curr] -= bf;

                        pivot[curr] = i;

                        return bf;
                    }
                }
            }

            pivot[curr] = size;

            return 0;
    };

    int net_flow = 0;
    vector<int> level(num_node, -1), pivot(num_node, 0);
    while (get_level(level)) {
        while (int bf = get_flow(source, INF, pivot, level)) {
            net_flow += bf;
        }

        fill (level.begin(), level.end(), -1);
        fill (pivot.begin(), pivot.end(), 0);
    }

    return net_flow;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<bool> is_prime(2222, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 2222; ++i) {
        if (!is_prime[i]) {
            continue;
        }

        int m = 2;
        while (true) {
            if (i*m >= 2222) {
                break;
            }

            is_prime[i*m] = false;
            ++m;
        }
    }

    int n;
    cin >> n;

    vector<int> num(n+1);
    vector<int> odd, even;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        if (num[i] % 2) {
            odd.emplace_back(i);
        } else {
            even.emplace_back(i);
        }
    }

    const int source = 0;
    const int drain = n+1;

    vector<int> ans;
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[num[1] + num[i]]) {
            continue;
        }

        Graph graph(n+2);

        for (const int& o: odd) {
            graph.add_edge(source, o, 1);
            graph.add_edge(o, source, 0);
        }

        for (const int& o: odd) {
            if (o == 1 || o == i) {
                continue;
            }
            for (const int& e: even) {
                if (e == 1 || e == i) {
                    continue;
                }

                if (is_prime[num[o] + num[e]]) {
                    graph.add_edge(o, e, 1);
                    graph.add_edge(e, o, 0);
                }
            }
        }

        for (const int& e: even) {
            graph.add_edge(e, drain, 1);
            graph.add_edge(drain, e, 0);
        }

        if (dinic(graph, source, drain) + 1 == n/2) {
            ans.emplace_back(num[i]);
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        sort(ans.begin(), ans.end());

        for (const int& a: ans) {
            cout << a << ' ';
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

