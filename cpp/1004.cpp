#include <iostream>

using namespace std;


inline int pow(int x) {
    return x * x;
}

bool inside(int a, int b, int x, int y, int rad) {
    return pow(x-a) + pow(y-b) < pow(rad);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        int x_start, y_start, x_end, y_end;
        cin >> x_start >> y_start >> x_end >> y_end;

        int num_planet;
        cin >> num_planet;

        int cnt = 0;
        while (num_planet--) {
            int x, y, rad;
            cin >> x >> y >> rad;

            if (inside(x_start, y_start, x, y, rad) ^ inside(x_end, y_end, x, y, rad)) {
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }

    return EXIT_SUCCESS;
}

