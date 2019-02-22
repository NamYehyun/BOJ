#include <iostream>

using namespace std;


int main(void) {
    char board[5][20] = {};
    for (int i = 0; i < 5; ++i) {
        scanf("%s", board[i]);
    }

    for (int col = 0; col < 20; ++col) {
        for (int row = 0; row < 5; ++row) {
            if (board[row][col]) {
                printf("%c", board[row][col]);
            }
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}

