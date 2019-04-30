#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b*b*b < a*a*a; ++b) {
            for (int c = b; c*c*c < a*a*a; ++c) {
                for (int d = c; d*d*d < a*a*a; ++d) {
                    if (a*a*a == b*b*b + c*c*c + d*d*d) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << '\n';
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

