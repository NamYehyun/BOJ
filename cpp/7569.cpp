#include <iostream>
#include <vector>

using namespace std;


const int dh[6] = {-1, 0, 0, 0, 0, 1};
const int dr[6] = {0, -1, 0, 1, 0, 0};
const int dc[6] = {0, 0, 1, 0, -1, 0};


class Pos {
public:
    int h, r, c;

    Pos(int _h, int _r, int _c) {
        h = _h;
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
        queue.reserve(100 * 100 * 100);
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
        return front == rear;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, R, C;
    cin >> C >> R >> H;

    Queue queue;

    vector<vector<vector<int>>> box(H, vector<vector<int>>(R, vector<int>(C)));
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                cin >> box[h][r][c];

                if (box[h][r][c] == 1) {
                    queue.enqueue(Pos(h, r, c));
                }
            }
        }
    }

    while (!queue.is_empty()) {
        Pos curr = queue.dequeue();
        for (int i = 0; i < 6; ++i) {
            int h = curr.h + dh[i];
            int r = curr.r + dr[i];
            int c = curr.c + dc[i];
            if ((0 <= h && h < H) && (0 <= r && r < R) && (0 <= c && c < C) && box[h][r][c] == 0) {
                box[h][r][c] = box[curr.h][curr.r][curr.c] + 1;
                queue.enqueue(Pos(h, r, c));
            }
        }
    }

    int day = 0;
    bool complete = true;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (box[h][r][c] == 0) {
                    complete = false;
                }

                if (day < box[h][r][c]) {
                    day = box[h][r][c];
                }
            }
        }
    }

    cout << (complete ? day-1 : -1) << endl;

    return EXIT_SUCCESS;
}

