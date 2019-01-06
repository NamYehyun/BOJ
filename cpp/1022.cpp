#include <iostream>

using namespace std;


int seq(int r, int c) {
    if (r == 0 && c == 0) {
        return 1;
    } else if (r > 0 && (-r <= c && c <= r)) {
        return (2 * r + 1) * (2 * r + 1) - (r - c);
    } else if (r < 0 && (r <= c && c <= -r)) {
        return (2 * r) * (2 * r) + (r - c + 1);
    } else if (0 < c) {
        return (2 * c - 1) * (2 * c - 1) - (r - c);
    } else {
        return (2 * c) * (2 * c) + (r - c + 1);
    }
}


int main(void) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

    int length = to_string(max(max(seq(r1, c1), seq(r1, c2)), max(seq(r2, c1), seq(r2, c2)))).length();

    for (int r = r1; r <= r2; ++r) {
        for (int c = c1; c <= c2; ++c) {
            printf("%*d ", length, seq(r, c));
        }
        printf("\n");
    }

    return EXIT_SUCCESS;;
}

