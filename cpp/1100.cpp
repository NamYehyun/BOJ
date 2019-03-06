#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    char board[10][10];
    for (int row = 0; row < 8; ++row) {
        scanf("%s", board[row]);
    }

    int count = 0;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            count += (board[row][col] == 'F') && ((row + col) % 2 == 0);
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

