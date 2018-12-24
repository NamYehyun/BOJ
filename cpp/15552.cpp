#include <iostream>

using namespace std;


int main(void) {
    int t;

    scanf("%d", &t);

    for (int _ = 1; _ <= t; ++_) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
    }
    
    return EXIT_SUCCESS;
}

