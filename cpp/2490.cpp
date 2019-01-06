#include <iostream>

using namespace std;


int main(void) {
    char result[5] = {'D', 'C', 'B', 'A', 'E'};

    for (int _ = 0; _ < 3; ++_) {
        int acc = 0;
        for (int i = 0; i < 4; ++i) {
            int tmp;
            scanf("%d", &tmp);
            acc += tmp;
        }

        printf("%c\n", result[acc]);
    }

    return EXIT_SUCCESS;
}

