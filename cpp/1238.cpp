#include <iostream>
#include <queue>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


class Path {
public:
    int to, dist;

    Path(int _to, int _dist): to(_to), dist(_dist) {}

    bool operator>(const Path& other) const {
        if (dist == other.dist) {
            return to > other.to;
        }

        return dist > other.dist;
    }
};


void dijkstra(int root, vector<int>& nodes, vector<vector<Path>>& adj_list, vector<int>& min_dist) {
    const int num_node = nodes.size();

    vector<bool> visited(num_node + 1, false);

    min_dist[root] = 0;

    priority_queue<Path, vector<Path>, greater<Path>> queue;
    queue.push(Path(root, min_dist[root]));

    while (!queue.empty()) {
        Path curr = queue.top(); queue.pop();
        int curr_node = curr.to;

        if (visited[curr_node]) {
            continue;
        }

        visited[curr_node] = true;

        for (Path next: adj_list[curr_node]) {
            int next_node = next.to;
            if (visited[next_node]) {
                continue;
            }

            int next_dist = curr.dist + next.dist;
            if (next_dist < min_dist[next_node]) {
                min_dist[next_node] = next_dist;
                queue.push(Path(next_node, next_dist));
            }
        }
    }

    return;
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_node, num_edge, root;
    cin >> num_node >> num_edge >> root;

    vector<int> nodes(num_node);
    for (int id = 1; id <= num_node; ++id) {
        nodes[id-1] = id;
    }

    vector<vector<Path>> adj_list(num_node + 1, vector<Path>());
    vector<vector<Path>> adj_list_rev(num_node + 1, vector<Path>());
    for (int edge = 0; edge < num_edge; ++edge) {
        int from, to, dist;
        cin >> from >> to >> dist;
        adj_list[from].push_back(Path(to, dist));
        adj_list_rev[to].push_back(Path(from, dist));
    }

    vector<int> min_dist(num_node + 1, INF);
    vector<int> min_dist_rev(num_node + 1, INF);
    
    dijkstra(root, nodes, adj_list, min_dist);
    dijkstra(root, nodes, adj_list_rev, min_dist_rev);


    auto max = [](int a, int b) -> int { return (a > b ? a : b); };

    int ans = 0;
    for (int node: nodes) {
        ans = max(ans, min_dist[node] + min_dist_rev[node]);
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

