#include <iostream>
#include <vector>

using namespace std;


const int MAX = 75;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<long long> fibo(MAX);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    long long n;
    cin >> n;

    vector<bool> zeckendorf(MAX, false);
    while (n > 0) {
        int idx = MAX-1;
        while ((idx >= 0) && n < fibo[idx]) {
            --idx;
        }

        zeckendorf[idx] = true;
        n -= fibo[idx];
    }

    for (int i = 0; i < MAX; ++i) {
        if (zeckendorf[i]) {
            cout << fibo[i] << endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}

