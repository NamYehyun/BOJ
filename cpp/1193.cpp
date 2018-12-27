#include <iostream>

using namespace std;


class Frac {
public:
    int numer;
    int denom;

    Frac(int n, int d) {
        numer = n;
        denom = d;
    }

    void print(void) {
        printf("%d/%d\n", numer, denom);
        return;
    }
};


Frac solve(int n, int group_size) {
    if (group_size < n) {
        return solve(n - group_size, group_size + 1);
    } else {
        if (group_size % 2 == 1) {
            int numer = group_size + 1 - n;
            int denom = n;
            return Frac(numer, denom);
        } else {
            int numer = n;
            int denom = group_size + 1 - n;
            return Frac(numer, denom);
        }
    }
}


int main(void) {
    int n;

    scanf("%d", &n);
    solve(n, 1).print();

    return EXIT_SUCCESS;
}

