#include <iostream>

using namespace std;


int main(void) {
    int n;

    scanf("%d", &n);

    int ten = n / 10;
    int one = n % 10;
    int count = 0;
    while(true) {
        ++count;

        int next_ten = one;
        int next_one = (ten + one) % 10;

        if (10 * next_ten + next_one == n) {
            break;
        }

        ten = next_ten;
        one = next_one;
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

