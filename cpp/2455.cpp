#include <iostream>

using namespace std;


int main(void) {
    int acc = 0;
    int max = 0;
    for (int i = 0; i < 4; ++i) {
        int sub, add;
        scanf("%d%d", &sub, &add);

        acc -= sub;
        acc += add;

        if (max < acc) {
            max = acc;
        }
    }

    printf("%d\n", max);
    
    return EXIT_SUCCESS;
}

