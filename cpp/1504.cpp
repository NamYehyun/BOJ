#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


class Path {
public:
    int to, dist;

    Path(int _to, int _dist) {
        to = _to;
        dist = _dist;
    }

    Path(const Path& other) {
        to = other.to;
        dist = other.dist;
    }

    bool operator<(const Path& other) const {
        return (dist < other.dist);
    }
};


class MinHeap {
public:
    int size;
    vector<Path> heap;

    MinHeap(void) {
        size = 0;
    }

    void insert(Path p) {
        heap.push_back(p);
        ++size;

        int curr = size-1;
        while (true) {
            int prev = (curr-1)/2;
            if (!(heap[curr] < heap[prev])) {
                break;
            }
            Path tmp = heap[prev];
            heap[prev] = heap[curr];
            heap[curr] = tmp;

            curr = prev;
        }

        return;
    }

    Path extract(void) {
        Path min_node = heap[0];
        heap[0] = heap[size-1];

        heap.pop_back();
        --size;

        int curr = 0;
        while (true) {
            int l_child = (2*curr+1 < size) ? 2*curr+1 : curr;
            int r_child = (2*curr+2 < size) ? 2*curr+2 : curr;

            int next = (heap[l_child] < heap[r_child]) ? l_child : r_child;
            if (!(heap[next] < heap[curr])) {
                break;
            }

            Path tmp = heap[next];
            heap[next] = heap[curr];
            heap[curr] = tmp;

            curr = next;
        }

        return min_node;
    }

    bool is_empty(void) {
        return (size == 0);
    }
};


void dijkstra(int root, vector<vector<Path>>& adj_list, vector<int>& min_dist) {
    MinHeap queue;
    queue.insert(Path(root, 0));

    while (!queue.is_empty()) {
        Path curr = queue.extract();
        if (min_dist[curr.to] < curr.dist) {
            continue;
        }

        min_dist[curr.to] = curr.dist;
        for (Path path: adj_list[curr.to]) {
            if (min_dist[path.to] < min_dist[curr.to] + path.dist) {
                continue;
            }

            queue.insert(Path(path.to, min_dist[curr.to] + path.dist));
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    vector<vector<Path>> adj_list(num_nodes+1, vector<Path>());
    for (int i = 0; i < num_edges; ++i) {
        int x, y, d;
        cin >> x >> y >> d;

        adj_list[x].emplace_back(y, d);
        adj_list[y].emplace_back(x, d);
    }

    int x, y;
    cin >> x >> y;

    vector<int> dist_1(num_nodes+1, INF);
    vector<int> dist_x(num_nodes+1, INF);
    vector<int> dist_y(num_nodes+1, INF);

    dijkstra(1, adj_list, dist_1);
    dijkstra(x, adj_list, dist_x);
    dijkstra(y, adj_list, dist_y);

    int n = num_nodes;

    int dist1 = INF;
    if (dist_1[x] != INF && dist_x[y] != INF && dist_y[n] != INF) {
        dist1 = dist_1[x] + dist_x[y] + dist_y[n];
    }

    int dist2 = INF;
    if (dist_1[y] != INF && dist_y[x] != INF && dist_x[n] != INF) {
        dist2 = dist_1[y] + dist_y[x] + dist_x[n];
    }

    int dist = (dist1 < dist2) ? dist1 : dist2;

    cout << ((dist != INF) ? dist : -1) << endl;

    return EXIT_SUCCESS;
}

