#include <iostream>

using namespace std;


int main(void) {
    int a, b, c;
    
    scanf("%d%d%d", &a, &b, &c);

    int mul = a * b * c;
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (true) {
        if (mul == 0) {
            break;
        }

        count[mul % 10] += 1;
        mul /= 10;
    }

    for (int i = 0; i <= 9; ++i) {
        printf("%d\n", count[i]);
    }

    return EXIT_SUCCESS;
}

