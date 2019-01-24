#include <iostream>
#include <vector>

using namespace std;


const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, -1, 0, 1};


class Pos {
public:
    int r, c;

    Pos(int _r, int _c) {
        r = _r;
        c = _c;
    }
};


class Queue {
public:
    int front, rear;
    vector<Pos> queue;

    Queue(void) {
        front = rear = 0;
        queue.reserve(100*100);
    }

    void enqueue(Pos p) {
        queue[rear] = p;
        ++rear;

        return;
    }

    Pos dequeue(void) {
        ++front;

        return queue[front-1];
    }

    bool is_empty(void) {
        return (front == rear);
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> maze(R, vector<int>(C));
    for (int r = 0; r < R; ++r) {
        string line;
        cin >> line;
        for (int c = 0; c < C; ++c) {
            maze[r][c] = (line[c] == '1') ? 0 : -1;
        }
    }

    Queue queue;

    maze[0][0] = 1;
    queue.enqueue(Pos(0, 0));

    while (!queue.is_empty()) {
        Pos curr = queue.dequeue();
        for (int i = 0; i < 4; ++i) {
            int r = curr.r + dr[i];
            int c = curr.c + dc[i];
            if ((0 <= r && r < R) && (0 <= c && c < C) && maze[r][c] == 0) {
                maze[r][c] = maze[curr.r][curr.c] + 1;
                queue.enqueue(Pos(r, c));
            }
        }
    }

    cout << maze[R-1][C-1] << endl;

    return EXIT_SUCCESS;
}

