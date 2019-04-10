#include <iostream>
#include <vector>

using namespace std;


const int top = 0;
const int east = 1;
const int west = 2;
const int north = 3;
const int south = 4;
const int bottom = 5;


class Board {
public:
    int nrow, ncol;
    vector<vector<int>> value;

    Board(int _nrow, int _ncol): nrow(_nrow), ncol(_ncol) {
        for (int row = 0; row < nrow; ++row) {
            value.push_back(vector<int>(ncol, 0));
        }
    }
};


class Dice {
public:
    int row, col;
    int eye[6];

    Dice(int _row, int _col): row(_row), col(_col) {
        for (int i = 0; i < 6; ++i) {
            eye[i] = 0;
        }
    }

    void move(int dir) {
        int tmp;
        switch(dir) {
          case north:
            tmp = eye[north];
            eye[north] = eye[top];
            eye[top] = eye[south];
            eye[south] = eye[bottom];
            eye[bottom] = tmp;
            --row; break;
          case south:
            tmp = eye[south];
            eye[south] = eye[top];
            eye[top] = eye[north];
            eye[north] = eye[bottom];
            eye[bottom] = tmp;
            ++row; break;
          case west:
            tmp = eye[west];
            eye[west] = eye[top];
            eye[top] = eye[east];
            eye[east] = eye[bottom];
            eye[bottom] = tmp;
            --col; break;
          case east:
            tmp = eye[east];
            eye[east] = eye[top];
            eye[top] = eye[west];
            eye[west] = eye[bottom];
            eye[bottom] = tmp;
            ++col; break;
        }

        return;
    }
};


class Game {
public:
    Board& board;
    Dice& dice;

    Game(Board& _board, Dice& _dice): board(_board), dice(_dice) {}
    
    bool safe(int dir) {
        switch(dir) {
          case north:
            return (0 <= dice.row-1 && dice.row-1 < board.nrow);
          case south:
            return (0 <= dice.row+1 && dice.row+1 < board.nrow);
          case west:
            return (0 <= dice.col-1 && dice.col-1 < board.ncol);
          case east:
            return (0 <= dice.col+1 && dice.col+1 < board.ncol);
          default:
            return false;
        }
    }

    int move(int dir) {
        if (safe(dir)) {
            dice.move(dir);
            if (board.value[dice.row][dice.col] == 0) {
                board.value[dice.row][dice.col] = dice.eye[bottom];
            } else {
                dice.eye[bottom] = board.value[dice.row][dice.col];
                board.value[dice.row][dice.col] = 0;
            }

            return dice.eye[top];
        }

        return -1;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int nrow, ncol, drow, dcol, nquery;
    cin >> nrow >> ncol >> drow >> dcol >> nquery;

    Board board(nrow, ncol);
    Dice dice(drow, dcol);

    for (int row = 0; row < nrow; ++row) {
        for (int col = 0; col < ncol; ++col) {
            cin >> board.value[row][col];
        }
    }

    Game game(board, dice);

    for (int query = 0; query < nquery; ++query) {
        int dir;
        cin >> dir;
        
        int top = game.move(dir);
        if (top >= 0) {
            cout << top << '\n';
        }
    }

    return EXIT_SUCCESS;
}

