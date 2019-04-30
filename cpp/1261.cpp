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

    int num_row, num_col;
    cin >> num_col >> num_row;

    vector<string> board(num_row);
    for (int row = 0; row < num_row; ++row) {
        cin >> board[row];
    }

    int num_node = num_row * num_col;
    vector<int> nodes(num_node);
    for (int id = 1; id <= num_node; ++id) {
        nodes[id-1] = id;
    }

    const int drow[4] = {-1, 0, 1, 0};
    const int dcol[4] = {0, 1, 0, -1};
    
    auto safe = [num_row, num_col](int row, int col) -> bool {
        return (0 <= row && row < num_row) && (0 <= col && col < num_col);
    };

    auto pos_to_id = [num_col](int row, int col) -> int {
        return num_col * row + col + 1;
    };

    vector<vector<Path>> adj_list(num_node + 1, vector<Path>());
    for (int row = 0; row < num_row; ++row) {
        for (int col = 0; col < num_col; ++col) {
            int curr = pos_to_id(row, col);
            for (int i = 0; i < 4; ++i) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                int prev = pos_to_id(nrow, ncol);
                if (safe(nrow, ncol)) {
                    adj_list[prev].push_back(Path(curr, (board[row][col] == '0' ? 0 : 1)));
                }
            }
        }
    }

    vector<int> min_dist(num_node + 1, INF);

    dijkstra(pos_to_id(0, 0), nodes, adj_list, min_dist);

    cout << min_dist[(pos_to_id(num_row-1, num_col-1))] << endl;

    return EXIT_SUCCESS;
}

