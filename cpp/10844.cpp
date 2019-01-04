#include <iostream>

using namespace std;


const int MAX_LEN = 100;
const int DIV = 1000000000;

int n;
int count[MAX_LEN + 1][10];


int main(void) {
    scanf("%d", &n);

    for (int msd = 0; msd <= 9; ++msd) {
        count[1][msd] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        count[len][0] = count[len - 1][1];
        for (int msd = 1; msd <= 8; ++msd) {
            count[len][msd] = (count[len - 1][msd - 1] + count[len - 1][msd + 1]) % DIV;
        }
        count[len][9] = count[len - 1][8];
    }

    int acc = 0;
    for (int msd = 1; msd <= 9; ++msd) {
        acc = (acc + count[n][msd]) % DIV;
    }

    printf("%d\n", acc);

    return EXIT_SUCCESS;
}

