#include <iostream>

using namespace std;


int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(a + b == c) {
        printf("%d+%d=%d\n", a, b, c);  
    } else if(a - b == c) {
        printf("%d-%d=%d\n", a, b, c);
    } else if(a * b == c) {
        printf("%d*%d=%d\n", a, b, c);
    } else if(a / b == c) {
        printf("%d/%d=%d\n", a, b, c);
    } else if(a == b + c) {
        printf("%d=%d+%d\n", a, b, c);
    } else if(a == b - c) {
        printf("%d=%d-%d\n", a, b, c);
    } else if(a == b * c) {
        printf("%d=%d*%d\n", a, b, c);
    } else if(a == b / c) {
        printf("%d=%d/%d\n", a, b, c);
    } else {
        while(true);
    }

    return EXIT_SUCCESS;
}

