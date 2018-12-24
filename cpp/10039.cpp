#include <iostream>

using namespace std;


int main(void) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        int score;
        scanf("%d", &score);

        sum += (40 < score) ? score : 40;
    }

    printf("%d\n", sum / 5);

    return EXIT_SUCCESS;
}

