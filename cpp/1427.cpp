#include <iostream>

using namespace std;


int main(void) {
    string num;
    int count[10] = {};

    cin >> num;

    int length = num.length();
    for (int i = 0; i < length; ++i) {
        count[num[i] - '0'] += 1;
    }

    for (int i = 9; i >= 0; --i) {
        for (int j = 0; j < count[i]; ++j) {
            printf("%d", i);
        }
    }

    printf("\n");

    return EXIT_SUCCESS;
}

