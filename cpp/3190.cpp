#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class List {
public:
    class Node {
    public:
        T value;
        Node* prev;
        Node* next;

        Node(T _value): value(_value), prev(nullptr), next(nullptr) {}
    };

    int size;
    Node* head;
    Node* tail;

    List(void): size(0), head(nullptr), tail(nullptr) {}

    int length(void) {
        return size;
    }

    void push_front(T value) {
        Node* new_node = new Node(value);
        if (size == 0) {
            head = tail = new_node;
        } else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }

        ++size;
    }

    void pop_back(void) {
        if (size == 0) {
            return;
        }

        tail = tail->prev;

        if (tail != nullptr) {
            delete tail->next;
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        --size;
    }
};


class Pos {
public:
    int row, col;
    Pos(int _row, int _col): row(_row), col(_col) {}
};


class Snake {
public:
    const int UP = 0;
    const int RIGHT = 1;
    const int DOWN = 2;
    const int LEFT = 3;

    const int drow[4] = {-1, 0, 1, 0};
    const int dcol[4] = {0, 1, 0, -1};

    int dir;
    List<Pos> body;

    Snake(void): dir(RIGHT) {
        body.push_front(Pos(0, 0));
    }

    Pos peek(void) {
        if (body.length() == 0) {
            return Pos(-1, -1);
        }

        Pos curr = body.head->value;

        return Pos(curr.row + drow[dir], curr.col + dcol[dir]);
    }

    Pos tail(void) {
        if (body.length() == 0) {
            return Pos(-1, -1);
        }

        return (body.tail)->value;
    }

    void turn_left(void) {
        dir = (dir + 3) % 4;
    }

    void turn_right(void) {
        dir = (dir + 1) % 4;
    }

    void grow(void) {
        body.push_front(peek());
    }

    void move(void) {
        body.push_front(peek());
        body.pop_back();
    }
};


class Game {
public:
    const int BLANK = 0;
    const int APPLE = 1;
    const int SNAKE = 2;

    Snake snake;

    int nrow, ncol;
    vector<vector<int>> board;

    Game(int _nrow, int _ncol): nrow(_nrow), ncol(_ncol) {
        for (int row = 0; row < nrow; ++row) {
            board.push_back(vector<int>(ncol, BLANK));
        }
    }

    bool is_safe(int row, int col) {
        return (0 <= row && row < nrow) && (0 <= col && col < ncol) && (board[row][col] != SNAKE);
    }

    bool is_safe(Pos pos) {
        return is_safe(pos.row, pos.col);
    }

    bool is_apple(int row, int col) {
        return is_safe(row, col) && (board[row][col] == APPLE);
    }

    bool is_apple(Pos pos) {
        return is_apple(pos.row, pos.col);
    }

    void add_apple(int row, int col) {
        board[row][col] = APPLE;
    }

    bool move_snake(void) {
        Pos next = snake.peek();
        Pos tail = snake.tail();

        if (is_safe(next)) {
            if (is_apple(next)) {
                snake.grow();
                board[next.row][next.col] = SNAKE;
            } else {
                snake.move();
                board[next.row][next.col] = SNAKE;
                board[tail.row][tail.col] = BLANK;
            }

            return true;
        }

        return false;
    }

    void turn_snake(char dir) {
        if (dir == 'L') {
            snake.turn_left();
        } else if (dir == 'D') {
            snake.turn_right();
        }

        return;
    }

    void print(void) {
        for (int row = 0; row < nrow; ++row) {
            for (int col = 0; col < ncol; ++col) {
                cout << board[row][col] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        return;
    }
};



int main(void) {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);

    int size;
    cin >> size;

    Game game(size, size);

    int num_apple;
    cin >> num_apple;
    for (int i = 0; i < num_apple; ++i) {
        int row, col;
        cin >> row >> col;
        game.add_apple(row-1, col-1);
    }

    int curr = 0;
    int num_shift;
    cin >> num_shift;
    for (int i = 0; i < num_shift; ++i) {
        int time;
        char dir;
        cin >> time >> dir;

        while (true) {
            if (curr == time) {
                break;
            }

            ++curr;
            if (!game.move_snake()) {
                cout << curr << endl;
                return EXIT_SUCCESS;
            }
        }

        game.turn_snake(dir);
    }

    while (true) {
        ++curr;
        if (!game.move_snake()) {
            cout << curr << endl;
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}

