#include <iostream>

using namespace std;


int main(void) {
    int t;

    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int rep;
        string line;

        cin >> rep >> line;

        int length = line.length();
        for (int i = 0; i < length; ++i) {
            for (int r = 0; r < rep; ++r) {
                printf("%c", line[i]);
            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

