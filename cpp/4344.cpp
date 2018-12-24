#include <iostream>

using namespace std;


const int MAX_N = 1000;

int main(void) {
    int t;
    
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int n;
        int score[MAX_N];

        scanf("%d", &n);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", score + i);
            sum += score[i];
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (sum < n * score[i]) {
                ++count;
            }
        }

        printf("%.3f%%\n", 100 * ((double) count)/((double) n));
    }
}

