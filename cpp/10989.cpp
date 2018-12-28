#include <iostream>

using namespace std;


const int MAX_ELT = 10000;


int main(void) {
    int n;
    int count[MAX_ELT + 1] = {};

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int elt;
        
        scanf("%d", &elt);
        
        count[elt] += 1;
    }

    for (int i = 0; i <= MAX_ELT; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            printf("%d\n", i);
        }
    }

    return EXIT_SUCCESS;
}

