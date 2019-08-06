#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string n_str;
    cin >> n_str;

    const int length = n_str.length();

    vector<int> digits;
    for (const auto& n: n_str) {
        digits.push_back(static_cast<int>(n - '0'));
    }

    long long l = 0;
    long long r = 0;
    long long p = 1;
    for (int i = 1; i < length; ++i) {
        p *= 10;
        r = 10 * r + digits[i];
    }
    
    vector<long long> cnt(10, 0);

    /* Leftmost digit */
    int digit = digits[0];
    for (int j = 1; j < digit; ++j) {
        cnt[j] += p;
    }
    cnt[digit] += (r+1);

    l = 10 * l + digit;
    p /= 10;
    r = (r != 0) ? (r % p) : r;

    /* Otherwise */
    for (int i = 1; i < length; ++i) {
        digit = digits[i];

        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                cnt[j] += (digit != 0) ? l*p : (l-1)*p + (r+1);
            } else if (j < digit) {
                cnt[j] += l*p + p;
            } else if (j == digit) {
                cnt[j] += l*p + (r+1);
            } else {
                cnt[j] += l*p;
            }
        }

        l = 10 * l + digit;
        p /= 10;
        r = (r != 0) ? (r % p) : r;
    }

    for (const auto& c: cnt) {
        cout << c << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

