#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;


class Graph {
public:
    int num_node;
    vector<vector<pair<int, int>>> out_edge;
    vector<vector<pair<int, int>>> in_edge;

    Graph(int _num_node): num_node(_num_node) {
        out_edge.resize(num_node+1, vector<pair<int, int>>());
        in_edge.resize(num_node+1, vector<pair<int, int>>());
    }

    void add_edge(int u, int v, int w) {
        out_edge[u].push_back(make_pair(v, w));
        in_edge[v].push_back(make_pair(u, w));
        return;
    }

    void add_edge(int u, int v) {
        add_edge(u, v, 1);
        return;
    }
};


void kosaraju(Graph& graph, vector<int>& result) {
    result.resize(graph.num_node+1, -1);
    vector<bool> visited(graph.num_node+1, false);
    vector<int> queue;

    function<void(int)> visit = [&visit, &graph, &visited, &queue](int curr) {
        if (!visited[curr]) {
            visited[curr] = true;
            for (pair<int, int> p: graph.out_edge[curr]) {
                visit(p.first);
            }
            queue.push_back(curr);
        }
    };

    for (int node = 1; node <= graph.num_node; ++node) {
        visit(node);
    }

    function<void(int, int)> assign = [&assign, &graph, &result](int curr, int root) {
        if (result[curr] < 0) {
            result[curr] = root;
            for (pair<int, int> p: graph.in_edge[curr]) {
                assign(p.first, root);
            }
        }
    };

    int size = queue.size();
    for (int i = size-1; i >= 0; --i) {
        assign(queue[i], queue[i]);
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_node, num_edge;
    cin >> num_node >> num_edge;

    Graph graph(num_node);
    for (int i = 0; i < num_edge; ++i) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    vector<int> root_of;
    kosaraju(graph, root_of);

    map<int, set<int>> SCC;
    for (int node = 1; node <= num_node; ++node) {
        SCC[root_of[node]].insert(node);
    }

    vector<pair<int, int>> min_elt_of_scc;
    for (auto const& scc: SCC) {
        min_elt_of_scc.emplace_back(*scc.second.begin(), scc.first);
    }

    sort(min_elt_of_scc.begin(), min_elt_of_scc.end());

    cout << SCC.size() << '\n';
    for (auto const& p: min_elt_of_scc) {
        auto const& scc = SCC[p.second];
        for (int const& node: scc) {
            cout << node << ' ';
        }
        cout << -1 << '\n';
    }

    return EXIT_SUCCESS;
}

