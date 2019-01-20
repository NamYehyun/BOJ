#include <iostream>

using namespace std;


const int CNT_MAX = 1000001;


int main (void) {
    long long min, max;
    cin >> min >> max;

    bool count[CNT_MAX];
    fill(count, count + CNT_MAX, true);

    for (long long i = 2; i * i <= max; ++i) {
        long long num = i * i;
        long long mul = min / num + (min % num != 0);

        while (num * mul <= max) {
            int offset = static_cast<int>(num * mul - min);
            count[offset] = false;

            ++mul;
        }
    }

    int ans = 0;
    int diff = static_cast<int>(max - min);
    for (int offset = 0; offset <= diff; ++offset) {
        if (count[offset]) {
            ++ans;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

