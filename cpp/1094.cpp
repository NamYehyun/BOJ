#include <iostream>

using namespace std;


int main(void) {
    int len;
    scanf("%d", &len);

    int count = 0;
    while (len != 0) {
        count += (len % 2);
        len /= 2;
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

