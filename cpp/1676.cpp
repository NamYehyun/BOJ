#include <iostream>

using namespace std;


int power5(int x) {
    if (x == 0) {
        return 1;
    }

    return 5 * power5(x-1);
}


int main(void) {
    int n;
    scanf("%d", &n);
    
    int count[5] = {};

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (i % power5(j) == 0) {
                ++count[j];
            }
        }
    }

    printf("%d\n", count[1] + count[2] + count[3] + count[4]);
    
    return EXIT_SUCCESS;
}

