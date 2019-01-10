#include <iostream>

using namespace std;


int main(void) {
    int m;
    scanf("%d", &m);

    int curr = 1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);

        if (curr == a || curr == b) {
            curr = a + b - curr;
        }
    }

    printf("%d\n", curr);
    
    return EXIT_SUCCESS;
}

