#include <iostream>

using namespace std;


const int MAX_N = 40;


int main(void) {
    int t;
    scanf("%d", &t);

    int count0[MAX_N+1];
    int count1[MAX_N+1];

    count0[0] = 1;
    count0[1] = 0;

    count1[0] = 0;
    count1[1] = 1;

    for (int i = 2; i <= MAX_N; ++i) {
        count0[i] = count0[i-1] + count0[i-2];
        count1[i] = count1[i-1] + count1[i-2];
    }

    for (int _ = 0; _ < t; ++_) {
        int n;
        scanf("%d", &n);

        printf("%d %d\n", count0[n], count1[n]);
    }

    return EXIT_SUCCESS;
}

