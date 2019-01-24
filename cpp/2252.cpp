#include <iostream>
#include <vector>

using namespace std;


class Queue {
public:
    int front, rear;
    vector<int> queue;

    Queue(void) {
        front = rear = 0;
        queue.reserve(40000);
    }

    void enqueue(int node) {
        queue[rear] = node;
        rear = (rear + 1) % 40000;

        return;
    }

    int dequeue(void) {
        int node = queue[front];
        front = (front + 1) % 40000;

        return node;
    }

    bool is_empty(void) {
        return (front == rear);
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes, num_pairs;
    cin >> num_nodes >> num_pairs;

    vector<int> indegree(num_nodes+1, 0);
    vector<vector<int>> adj_list(num_nodes+1, vector<int>());
    for (int i = 0; i < num_pairs; ++i) {
        int x, y;
        cin >> x >> y;

        adj_list[x].push_back(y);
        ++indegree[y];
    }

    Queue queue;
    for (int node = 1; node <= num_nodes; ++node) {
        if (indegree[node] == 0) {
            queue.enqueue(node);
        }
    }

    while (!queue.is_empty()) {
        int node = queue.dequeue();
        for (int next: adj_list[node]) {
            --indegree[next];

            if (indegree[next] == 0) {
                queue.enqueue(next);
            }
        }

        cout << node << ' ';
        indegree[node] = -1;
    }

    cout << endl;

    return EXIT_SUCCESS;
}

