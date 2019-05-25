#include <algorithm>
#include <functional>
#include <iostream>
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


int kosaraju(Graph& graph, vector<int>& result) {
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

    int num_scc = 0;
    int size = queue.size();
    for (int i = size-1; i >= 0; --i) {
        if (result[queue[i]] < 0) {
            ++num_scc;
            assign(queue[i], num_scc);
        }
    }

    return num_scc;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_node, num_edge, start, end;
    cin >> num_node >> num_edge >> start >> end;

    Graph graph(num_node);
    for (int i = 0; i < num_edge; ++i) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    vector<bool> visited(num_node+1, false);
    function<bool(int, int)> visitable = [&visitable, &graph, &visited](int curr, int dst) -> bool {
        if (curr == dst) {
            return true;
        }

        visited[curr] = true;
        for (auto const& edge: graph.out_edge[curr]) {
            int next = edge.first;
            if (!visited[next] && visitable(next, dst)) {
                return true;
            }
        }

        return false;
    };

    if (!visitable(start, end)) {
        cout << 0 << endl;
        return EXIT_SUCCESS;
    }

    vector<int> node_to_scc;
    int num_scc = kosaraju(graph, node_to_scc);

    vector<int> scc_size(num_scc+1, 0);
    for (int node = 1; node <= num_node; ++node) {
        scc_size[node_to_scc[node]] += 1;
    }

    Graph graph_scc(num_scc);
    for (int node = 1; node <= num_node; ++node) {
        int u = node_to_scc[node];
        for (auto const& edge: graph.out_edge[node]) {
            int v = node_to_scc[edge.first];
            int w = scc_size[v];
            if (u != v) {
                graph_scc.add_edge(u, v, w);
            }
        }
    }

    for (int scc = 1; scc <= num_scc; ++scc) {
        sort(graph_scc.out_edge[scc].begin(), graph_scc.out_edge[scc].end());
        graph_scc.out_edge[scc].erase(unique(graph_scc.out_edge[scc].begin(), graph_scc.out_edge[scc].end()), graph_scc.out_edge[scc].end());
    }

    int scc_start = node_to_scc[start];
    int scc_end = node_to_scc[end];

    vector<int> memo(num_scc+1, 0);
    memo[scc_start] = scc_size[scc_start];
    
    for (int scc = scc_start; scc <= scc_end; ++scc) {
        for (auto const& edge: graph_scc.out_edge[scc]) {
            int next_scc = edge.first;
            int weight = edge.second;
            memo[next_scc] = max(memo[next_scc], memo[scc] + weight);
        }
    }

    cout << memo[scc_end] << endl;

    return EXIT_SUCCESS;
}

