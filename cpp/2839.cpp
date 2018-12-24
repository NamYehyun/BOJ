#include <iostream>

using namespace std;


int main(void) {
    int N;

    scanf("%d", &N);

    int count = -1;
    for (int count3 = (N / 3); count3 >= 0; --count3) {
        int count5 = (N - 3 * count3) / 5;
        if (3 * count3  + 5 * count5 == N) {
            count = count3 + count5;
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

