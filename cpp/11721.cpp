#include <iostream>

using namespace std;


int main(void) {
    string line;

    cin >> line;

    int length = line.length();
    for (int i = 0; i < length; ++i) {
        printf("%c", line[i]);
        if (i % 10 == 9)
            printf("\n");
    }

    return EXIT_SUCCESS;
}

