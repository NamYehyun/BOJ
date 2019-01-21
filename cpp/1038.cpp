#include <iostream>

using namespace std;


int memo[11][11];


int count(int len, int msd) {
    if (!(1 <= len && len <= 10) || !(0 <= msd && msd <= 9)) {
        return 0;
    }

    if (memo[len][msd] != -1) {
        return memo[len][msd];
    }


    if (len == 1) {
        return memo[len][msd] = 1;
    } else {
        int acc = 0;
        for (int nsd = 0; nsd < msd; ++nsd) {
            acc += count(len-1, nsd);
        }

        return memo[len][msd] = acc;
    }
}


int count(int len) {
    if (!(1 <= len && len <= 10)) {
        return 0;
    }

    if (memo[len][10] != -1) {
        return memo[len][10];
    }
    
    int acc = 0;
    for (int msd = 0; msd <= 9; ++msd) {
        acc += count(len, msd);
    }

    return memo[len][10] = acc;
}


int main(void) {
    for (int len = 1; len <= 10; ++len) {
        for (int msd = 0; msd <= 10; ++msd) {
            memo[len][msd] = -1;
        }
    }

    int n;
    cin >> n;
    
    ++n;

    int acc = 0;
    int len = 1;
    while (true) {
        if (10 < len) {
            cout << -1 << endl;
            return EXIT_SUCCESS;
        }

        int c = count(len);

        if (n <= acc + c) {
            break;
        }

        acc += c;
        ++len;
    }

    int cnt = acc;
    int pos = len;
    long long ans = 0;
    while (true) {
        if (pos == 0) {
            break;
        }

        int digit = 0;
        while (true) {
            int c = count(pos, digit);

            if (n <= cnt + c) {
                break;
            }

            cnt += c;
            ++digit;
        }

        ans = 10 * ans + static_cast<long long>(digit);

        --pos;
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

