#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7fffffff;


class Node {
public:
    int id;
    int dist;

    Node(int _id, int _dist) {
        id = _id;
        dist = _dist;
    }

    bool operator<(const Node& other) {
        return dist < other.dist;
    }
};


class PriorityQueue {
public:
    int size;
    vector<Node> min_heap;

    PriorityQueue(void) {
        size = 0;
    }

    void enqueue(Node n) {
        min_heap.push_back(n);
        ++size;

        int curr = size-1;
        while (true) {
            int parent = (curr - 1) / 2;

            if (parent == curr) {
                break;
            }

            if (min_heap[curr] < min_heap[parent]) {
                Node tmp = min_heap[parent];
                min_heap[parent] = min_heap[curr];
                min_heap[curr] = tmp;
            } else {
                break;
            }

            curr = parent;
        }

        return;
    }

    Node dequeue(void) {
        Node min_node = min_heap[0];

        min_heap[0] = min_heap[size-1];
        min_heap.pop_back();
        --size;

        int curr = 0;
        while (true) {
            int l_child = (2*curr+1 < size) ? 2*curr+1 : curr;
            int r_child = (2*curr+2 < size) ? 2*curr+2 : curr;

            int next = (min_heap[l_child] < min_heap[r_child]) ? l_child : r_child;

            if (min_heap[next] < min_heap[curr]) {
                Node tmp = min_heap[next];
                min_heap[next] = min_heap[curr];
                min_heap[curr] = tmp;
            } else {
                break;
            }

            curr = next;
        }

        return min_node;
    }

    bool empty(void) {
        return size == 0;
    }

    void print(void) {
        cout << "[ ";
        for (auto n: min_heap) {
            cout << "(" << n.id << ", " << n.dist << ") ";
        }
        cout << "]" << endl;

        return;
    }
};


void dijkstra(int root, vector<vector<Node>>& adj_list, vector<int>& result) {
    PriorityQueue queue;

    queue.enqueue(Node(root, 0));

    while (!queue.empty()) {
        Node curr = queue.dequeue();

        if (result[curr.id] <= curr.dist) {
            continue;
        }

        result[curr.id] = curr.dist;
        for (auto next: adj_list[curr.id]) {
            if (result[curr.id] + next.dist < result[next.id]) {
                queue.enqueue(Node(next.id, result[curr.id] + next.dist));                
            }
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes;
    cin >> num_nodes;

    vector<vector<Node>> adj_list(num_nodes+1, vector<Node>());
    for (int _ = 0; _ < num_nodes; ++_) {
        int x;
        cin >> x;

        while (true) {
            int y;
            cin >> y;

            if (y == -1) {
                break;
            }

            int dist;
            cin >> dist;

            adj_list[x].push_back(Node(y, dist));
        }
    }

    vector<int> result1(num_nodes+1, INF);
    dijkstra(1, adj_list, result1);

    int max1 = 0;
    int rad1 = 0;
    for (int i = 1; i <= num_nodes; ++i) {
        if (max1 < result1[i]) {
            max1 = result1[i];
            rad1 = i;
        }
    }

    vector<int> result2(num_nodes+1, INF);
    dijkstra(rad1, adj_list, result2);

    int max2 = 0;
    int rad2 = 0;
    for (int i = 1; i <= num_nodes; ++i) {
        if (max2 < result2[i]) {
            max2 = result2[i];
            rad2 = i;
        }
    }

    cout << max2 << endl;

    return EXIT_SUCCESS;
}

