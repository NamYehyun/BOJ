#include <iostream>

using namespace std;


int main(void) {
    int n;
    double sum, max = 0;

    scanf("%d", &n);

    for (int _ = 0; _ < n; ++_) {
        double score;
        scanf("%lf", &score);

        if (max < score) {
            max = score;
        }

        sum += score;
    }

    printf("%f\n", (100/max) * (sum / n));

    return EXIT_SUCCESS;
}

