#include <iostream>
#include <vector>

using namespace std;


const int MAX = 1000;

const int drow[4] = {-1, 0, 1, 0};
const int dcol[4] = {0, -1, 0, 1};


class Pos {
public:
    int row;
    int col;

    Pos(int _row, int _col) {
        row = _row;
        col = _col;
    }
};


class Queue {
public:
    int front;
    int rear;
    vector<Pos> queue;

    Queue(void) {
        front = rear = 0;
        queue.reserve(MAX * MAX);
    }

    Queue(const Queue& other) {
        front = other.front;
        rear = other.rear;
        queue = other.queue;
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

    void print(void) {
        cout << "queue: [ ";
        for (int i = front; i < rear; ++i) {
            cout << "(" << queue[i].row << "," << queue[i].col << ") ";
        }
        cout << "]" << endl;

        return;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_row, num_col;
    cin >> num_col >> num_row;

    Queue queue;

    vector<vector<int>> box(num_row, vector<int>(num_col));
    for (int row = 0; row < num_row; ++row) {
        for (int col = 0; col < num_col; ++col) {
            cin >> box[row][col];

            if (box[row][col] == 1) {
                queue.enqueue(Pos(row, col));
            }
        }
    }

    while (!queue.is_empty()) {
        Pos curr = queue.dequeue();
        for (int i = 0; i <= 4; ++i) {
            int row = curr.row + drow[i];
            int col = curr.col + dcol[i];

            if ((0 <= row && row < num_row) && (0 <= col && col < num_col) && box[row][col] == 0) {
                box[row][col] = box[curr.row][curr.col] + 1;
                queue.enqueue(Pos(row, col));
            }
        }
    }


    int day = 0;
    bool complete = true;
    for (int row = 0; row < num_row; ++row) {
        for (int col = 0; col < num_col; ++col) {
            if (box[row][col] == 0) {
                complete = false;
            }

            if (day < box[row][col]) {
                day = box[row][col];
            }
        }
    }

    cout << (complete ? day-1 : -1) << endl;

    return EXIT_SUCCESS;
}

