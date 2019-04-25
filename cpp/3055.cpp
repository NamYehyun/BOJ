#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7fffffff;

const int drow[4] = {-1, 0, 1, 0};
const int dcol[4] = {0, 1, 0, -1};


template <typename T>
class Queue {
private:
    int size, front, rear;
    vector<T> queue;

public:
    Queue(void): size(10000), front(0), rear(0) {
        queue.resize(size);
    }

    void enqueue(T elt) {
        queue[rear] = elt;
        rear = (rear + 1) % size;
        
        return;
    }

    T dequeue(void) {
        T elt = queue[front];
        front = (front + 1) % size;

        return elt;
    }

    bool is_empty(void) {
        return (front == rear);
    }

    void clear(void) {
        front = rear = 0;
        
        return;
    }

    void print(void) {
        for (int i = front; i < rear; ++i) {
            queue[i].print();
        }
        cout << endl;

        return;
    }
};


class Pos {
public:
    int row, col;
    
    Pos(void): row(-1), col(-1) {};

    Pos(int _row, int _col): row(_row), col(_col) {};

    void print(void) {
        cout << "(" << row << "," << col << ")";
        return;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int nrow, ncol;
    cin >> nrow >> ncol;

    vector<string> input(nrow);
    for (int row = 0; row < nrow; ++row) {
        cin >> input[row];
    }

    int row_s, col_s, row_d, col_d;
    vector<vector<int>> flow_time(nrow, vector<int>(ncol, INF));
    Queue<Pos>* queue = new Queue<Pos>();
    Queue<Pos>* next_queue = new Queue<Pos>();
    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            if (input[row][col] == '*') {
                flow_time[row][col] = 0;
                queue->enqueue(Pos(row, col));
            } else if (input[row][col] == 'X') {
                flow_time[row][col] = 0;
            } else if (input[row][col] == 'S') {
                row_s = row;
                col_s = col;
            } else if (input[row][col] == 'D') {
                flow_time[row][col] = INF;
                row_d = row;
                col_d = col;
            }
        }
    }

    auto safe = [nrow, ncol](int row, int col) -> bool {
        return (0 <= row && row < nrow) && (0 <= col && col < ncol);
    };

    auto print_flow_time = [nrow, ncol, flow_time]() {
        for (int row = 0; row < nrow; ++row) {
            for (int col = 0; col < ncol; ++col) {
                if (flow_time[row][col] == INF) {
                    cout << '.' << ' ' ;
                } else {
                    cout << flow_time[row][col] % 10 << ' ';
                }
            }
            cout << endl;
        }
        cout << endl;
    };

    int time = 1;
    while (true) {
        if (queue->is_empty()) {
            break;
        }

        next_queue->clear();

        while (!(queue->is_empty())) {
            Pos curr = queue->dequeue();
            for (int i = 0; i < 4; ++i) {
                int row = curr.row + drow[i];
                int col = curr.col + dcol[i];
                if (safe(row, col) && flow_time[row][col] == INF && !(row == row_d && col == col_d)) {
                    flow_time[row][col] = time;
                    next_queue->enqueue(Pos(row, col));
                }
            }
        }

        Queue<Pos>* tmp = queue;
        queue = next_queue;
        next_queue = tmp;
        
        ++time;
    }

    queue->clear();
    next_queue->clear();

    vector<vector<int>> move_time(nrow, vector<int>(ncol, INF));
    move_time[row_s][col_s] = 0;
    queue->enqueue(Pos(row_s, col_s));

    time = 1;
    while (true) {
        if (queue->is_empty()) {
            break;
        }

        next_queue->clear();

        while (!(queue->is_empty())) {
            Pos curr = queue->dequeue();
            for (int i = 0; i < 4; ++i) {
                int row = curr.row + drow[i];
                int col = curr.col + dcol[i];
                if (safe(row, col) && flow_time[row][col] > time && move_time[row][col] == INF) {
                    move_time[row][col] = time;
                    next_queue->enqueue(Pos(row, col));
                }
            }
        }

        Queue<Pos>* tmp = queue;
        queue = next_queue;
        next_queue = tmp;

        ++time;
    }

    if (move_time[row_d][col_d] != INF) {
        cout << move_time[row_d][col_d] << endl;
    } else {
        cout << "KAKTUS" << endl;
    }

    return EXIT_SUCCESS;
}

