#include <iostream>
#include <vector>

using namespace std;


const long long INF = 0x7fffffffffffffff;


template <typename T>
class MinHeap {
private:
    int size;
    vector<T> tree;

    inline int parent(int curr) {
        return (curr - 1) / 2;
    }

    inline int left_child(int curr) {
        return 2 * curr + 1;
    }

    inline int right_child(int curr) {
        return 2 * curr + 2;
    }

public:
    MinHeap(void): size(0) {
        tree.resize(100000);
    }

    MinHeap(int _size): size(0) {
        tree.resize(_size);
    }
    
    void insert(T elt) {
        tree[size] = elt;
        int curr = size;
        ++size;

        while (true) {
            int next = parent(curr);
            
            if (tree[curr] < tree[next]) {
                T tmp = tree[next];
                tree[next] = tree[curr];
                tree[curr] = tmp;
            } else {
                break;
            }

            curr = next;
        }

        return;
    }

    T remove_min(void) {
        T min_elt = tree[0];
        
        --size;
        tree[0] = tree[size];
        int curr = size;

        while (true) {
            int next_l = (left_child(curr) < size) ? left_child(curr) : curr;
            int next_r = (right_child(curr) < size) ? right_child(curr) : curr;
            int next = (tree[next_l] < tree[next_r]) ? next_l : next_r;

            if (tree[next] < tree[curr]) {
                T tmp = tree[next];
                tree[next] = tree[curr];
                tree[curr] = tmp;
            } else {
                break;
            }

            curr = next;
        }

        return min_elt;
    }

    bool is_empty(void) {
        return (size == 0);
    }
};


class Path{
public:
    int dest;
    long long dist;

    Path(void): dest(0), dist(0) {};

    Path(int _dest, long long _dist): dest(_dest), dist(_dist) {};

    bool operator<(const Path& other) const {
        return dist < other.dist;
    }
};


long long dijkstra(int src, int dst, int num_node, vector<vector<Path>>& adj_list) {
    MinHeap<Path> queue;
    vector<long long> min_dist(num_node+1, INF);

    min_dist[src] = 0;
    queue.insert(Path(src, min_dist[src]));

    while (!queue.is_empty()) {
        Path min_path = queue.remove_min();

        int curr = min_path.dest;
        long long curr_dist = min_path.dist;

        for (Path path: adj_list[curr]) {
            int next = path.dest;
            long long next_dist = curr_dist + path.dist;

            if (next_dist < min_dist[next]) {
                min_dist[next] = next_dist;
                queue.insert(Path(next, next_dist));
            }
        }
    }

    return min_dist[dst];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_node, num_edge;
    cin >> num_node >> num_edge;

    vector<vector<Path>> adj_list(num_node+1, vector<Path>());
    for (int edge = 0; edge < num_edge; ++edge) {
        int src, dst;
        long long dist;
        cin >> src >> dst >> dist;

        adj_list[src].emplace_back(dst, dist);
    }

    int src, dst;
    cin >> src >> dst;

    cout << dijkstra(src, dst, num_node, adj_list) << endl;

    return EXIT_SUCCESS;
}

