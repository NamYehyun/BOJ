#include <iostream>

using namespace std;


int main(void) {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    int round = 0;
    while (true) {
        if (a == b) {
            break;
        }

        a = (a + 1) / 2;
        b = (b + 1) / 2;

        ++round;        
    }

    printf("%d\n", round);

    return EXIT_SUCCESS;
}

