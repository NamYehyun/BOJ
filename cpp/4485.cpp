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

    int test = 0;

    while (true) {
        ++test;

        int size;
        cin >> size;

        if (!size) {
            break;
        }

        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, 1, 0, -1};

        const int num_node = size*size;

        auto safe = [size](int row, int col) -> bool {
            return (0 <= row && row < size) && (0 <= col && col < size);
        };

        auto pos_to_id = [size](int row, int col) -> int {
            return size * row + col + 1;
        };

        vector<int> nodes(num_node);
        for (int id = 1; id <= num_node; ++id) {
            nodes[id-1] = id;
        }

        int initial_cost = -1;
        vector<vector<Path>> adj_list(num_node + 1, vector<Path>());
        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; ++c) {
                int cost;
                cin >> cost;

                if (initial_cost < 0) {
                    initial_cost = cost;
                }

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (safe(nr, nc)) {
                        adj_list[pos_to_id(nr, nc)].push_back(Path(pos_to_id(r, c), cost));
                    }
                }
            }
        }

        vector<int> min_dist(num_node + 1, INF);

        dijkstra(pos_to_id(0, 0), nodes, adj_list, min_dist);

        cout << "Problem " << test << ": " << min_dist[pos_to_id(size-1, size-1)] + initial_cost << '\n';
    }
    
    return EXIT_SUCCESS;
}

