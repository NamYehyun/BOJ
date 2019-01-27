#include <iostream>
#include <queue>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


class Path {
public:
    int to, cost, dist;

    Path(int _to, int _cost, int _dist) {
        to = _to;
        cost = _cost;
        dist = _dist;
    }

    Path(const Path& other) {
        to = other.to;
        cost = other.cost;
        dist = other.dist;
    }

    void print(void) {
        cout << "(" << to << "," << cost << "," << dist << ") ";
    }
};


class Cmp {
public:
    bool operator()(const Path& p1, const Path& p2) const {
        return p1.dist > p2.dist;
    }
};


void dijkstra(int root, int max_cost, vector<vector<Path>>& adj_list, vector<vector<int>>& min_dist) {
    priority_queue<Path, vector<Path>, Cmp> queue;

    min_dist[1][0] = 0;
    queue.push(Path(root, 0, 0));

    while (!queue.empty()) {
        Path curr = queue.top();
        queue.pop();

        if ((min_dist[curr.to][curr.cost] < curr.dist) || (max_cost < curr.cost)) {
            continue;
        }

        min_dist[curr.to][curr.cost] = curr.dist;
        for (Path& next: adj_list[curr.to]) {
            int to = next.to;
            int cost = curr.cost + next.cost;
            int dist = curr.dist + next.dist;

            if ((cost <= max_cost) && (dist < min_dist[to][cost])) {
                min_dist[to][cost] = dist;
                queue.push(Path(to, cost, dist));
            }
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<vector<Path>> adj_list(100+1, vector<Path>());
    vector<vector<int>> min_dist(100+1, vector<int>(10000+1, INF));
    while (t--) {
        int num_nodes, max_cost, num_edges;
        cin >> num_nodes >> max_cost >> num_edges;

        for (int _ = 0; _ < num_edges; ++_) {
            int x, y, c, d;
            cin >> x >> y >> c >> d;
            adj_list[x].emplace_back(y, c, d);
        }

        dijkstra(1, max_cost, adj_list, min_dist);

        int LA = num_nodes;
        int dist = INF;
        for (int& d: min_dist[LA]) {
            if (d < dist) {
                dist = d;
            }
        }

        if (dist != INF) {
            cout << dist << '\n';
        } else {
            cout << "Poor KCM\n";
        }

        for (int i = 0; i <= 100; ++i) {
            adj_list[i].clear();
            for (int j = 0; j <= 10000; ++j) {
                min_dist[i][j] = INF;
            }
        }
    }

    return EXIT_SUCCESS;
}

