#include <iostream>

using namespace std;


int main(void) {
    int arr[9];

    for (int i = 1; i <= 8; ++i) {
        scanf("%d", arr + i);
    }

    bool ascending = true;
    for (int i = 1; i <= 8; ++i) {
        if (arr[i] != i) {
            ascending = false;
        }
    }

    if (ascending) {
        printf("ascending\n");
        return EXIT_SUCCESS;
    }

    bool descending = true;
    for (int i = 1; i <= 8; ++i) {
        if (arr[9 - i] != i) {
            descending = false;
        }
    }

    if (descending) {
        printf("descending\n");
        return EXIT_SUCCESS;
    }

    printf("mixed\n");

    return EXIT_SUCCESS;
}

