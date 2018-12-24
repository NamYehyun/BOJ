#include <iostream>

using namespace std;

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;

    return;
}

int main(void) {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (a > b) swap(&a, &b);
    if (b > c) swap(&b, &c);
    if (a > b) swap(&a, &b);

    printf("%d\n", b);
    
    return EXIT_SUCCESS;
}

