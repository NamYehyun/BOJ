#include <iostream>

using namespace std;


bool is_hansu(int n) {
    int a = (n / 1000) % 10;
    int b = (n / 100) % 10;
    int c = (n / 10) % 10;
    int d = n % 10;

    if ((a - b == b - c) && (b - c == c - d)) {
        return true;
    }

    if ((a == 0) && (b - c == c - d)) {
        return true;
    }

    if ((a == 0) && (b == 0)) {
        return true;
    }

    return false;
}


int main(void) {
    int n;
    
    scanf("%d", &n);

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (is_hansu(i)) {
            ++count;
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

