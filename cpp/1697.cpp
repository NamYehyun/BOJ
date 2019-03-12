#include <iostream>
#include <vector>

using namespace std;


const int MAX = 100000;
const int INF = 0x7f7f7f7f;


class Queue {
public:
    int front, rear;
    vector<int> queue;

    Queue(void) {
        front = rear = 0;
        queue.resize(MAX+1);
    }

    void enqueue(int e) {
        queue[rear] = e;
        ++rear;
        return;
    }

    int dequeue(void) {
        ++front;
        return queue[front-1];
    }

    bool empty(void) {
        return front == rear;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << 0 << endl;
        return EXIT_SUCCESS;
    }

    vector<int> dist(MAX+1, INF);
    Queue queue;

    dist[n] = 0;
    queue.enqueue(n);

    while (!queue.empty()) {
        int curr = queue.dequeue();
        
        if (curr - 1 >= 0 && dist[curr] + 1 < dist[curr-1]) {
            dist[curr-1] = dist[curr] + 1;
            if (curr - 1 == k) {
                break;
            }

            queue.enqueue(curr-1);
        }

        if (curr + 1 <= MAX && dist[curr] + 1 < dist[curr+1]) {
            dist[curr+1] = dist[curr] + 1;
            if (curr + 1 == k) {
                break;
            }

            queue.enqueue(curr+1);
        }

        if (2 * curr <= MAX && dist[curr] + 1 < dist[2*curr]) {
            dist[2*curr] = dist[curr] + 1;
            if (2 * curr == k) {
                break;
            }

            queue.enqueue(2*curr);
        }
    }

    cout << dist[k] << endl;

    return EXIT_SUCCESS;
}

