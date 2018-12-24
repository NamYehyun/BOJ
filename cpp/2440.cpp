#include <iostream>

using namespace std;


int main(void) {
    int n;

    scanf("%d", &n);

    for (int num_star = n; num_star >= 1; --num_star) {
        for (int star = 1; star <= num_star; ++star) {
            printf("*");
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

