#include <iostream>
#include <vector>

using namespace std;


class MinHeap {
public:
    int size;
    vector<int> heap;

    MinHeap(void) {
        size = 0;
        heap.reserve(40000);
    }

    void insert(int node) {
        int curr = size;
        heap[curr] = node;
        ++size;

        while (true) {
            int prev = (curr-1)/2;
            if (heap[curr] < heap[prev]) {
                int tmp = heap[prev];
                heap[prev] = heap[curr];
                heap[curr] = tmp;
                
                curr = prev;
            } else {
                break;
            }
        }

        return;
    }

    int extract(void) {
        int root = heap[0];

        --size;
        heap[0] = heap[size];
        
        int curr = 0;
        while (true) {
            int l = (2*curr+1 < size) ? 2*curr+1 : curr;
            int r = (2*curr+2 < size) ? 2*curr+2 : curr;

            int next = (heap[l] < heap[r]) ? l : r;
            if (heap[curr] > heap[next]) {
                int tmp = heap[next];
                heap[next] = heap[curr];
                heap[curr] = tmp;

                curr = next;
            } else {
                break;
            }
        }

        return root;
    }

    bool empty(void) {
        return (size == 0);
    }

    void print(void) {
        cout << "[ ";
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << ' ';
        }
        cout << "]" << endl;

        return;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes, num_pairs;
    cin >> num_nodes >> num_pairs;
    
    vector<vector<int>> adj_list(num_nodes+1, vector<int>());
    vector<int> indegree(num_nodes+1, 0);
    for (int i = 0; i < num_pairs; ++i) {
        int x, y;
        cin >> x >> y;

        adj_list[x].push_back(y);
        ++indegree[y];
    }

    MinHeap queue;
    for (int node = 1; node <= num_nodes; ++node) {
        if (indegree[node] == 0) {
            queue.insert(node);
        }
    }

    while (!queue.empty()) {
        int node = queue.extract();
        for (int next: adj_list[node]) {
            --indegree[next];
            if (indegree[next] == 0) {
                queue.insert(next);
            }
        }

        cout << node << ' ';
        indegree[node] = -1;
    }

    cout << endl;

    return EXIT_SUCCESS;
}

