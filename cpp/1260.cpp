#include <iostream>

using namespace std;


const int MAX_NODE = 1000;
const int MAX_EDGE = 10000;
const int ERROR = -1;


class Queue {
public:
    int front;
    int rear;
    int queue[MAX_NODE + 10];

    Queue(void) {
        front = 0;
        rear = 0;
    }

    void enqueue(int elt) {
        queue[rear] = elt;
        ++rear;

        return;
    }

    int dequeue(void) {
        if (front == rear) {
            return ERROR;
        } else {
            ++front;
            return queue[front - 1];
        }
    }

    bool empty(void) {
        return front == rear;
    }
};


int num_nodes, num_edges, root;
bool edge[MAX_NODE + 10][MAX_NODE + 10];


void dfs_help(int curr, bool* visited) {
    visited[curr] = true;
    printf("%d ", curr);

    for (int next = 1; next <= num_nodes; ++next) {
        if ((!visited[next]) && edge[curr][next]) {
            dfs_help(next, visited);
        }
    }

    return;
}

void dfs(int root) {
    bool visited[MAX_NODE + 10] = {};
    dfs_help(root, visited);
    printf("\n");
    return;
}


void bfs(int root) {
    bool visited[MAX_NODE + 10] = {};

    int curr;
    Queue q;

    curr = root;
    visited[curr] = true;
    q.enqueue(curr);

    while (!q.empty()) {
        int curr = q.dequeue();
        printf("%d ", curr);

        for (int next = 1; next <= num_nodes; ++next) {
            if ((!visited[next]) && edge[curr][next]) {
                visited[next] = true;
                q.enqueue(next);
            }
        }
    }

    printf("\n");

    return;
}


int main(void) {
    scanf("%d%d%d", &num_nodes, &num_edges, &root);
    for (int i = 0; i < num_edges; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);

        edge[x][y] = true;
        edge[y][x] = true;
    }

    dfs(root);
    bfs(root);

    return EXIT_SUCCESS;
}

