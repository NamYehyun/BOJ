#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    long long sum;
    cin >> n >> sum;

    vector<long long> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int lo = 0;
    int hi = 0;
    int cnt = 0;
    long long acc = seq[0];
    while (true) {
        if (acc == sum) {
            ++cnt;

            if (lo == n-1 || hi == n-1) {
                break;
            }

            ++hi;
            acc += seq[hi];

            acc -= seq[lo];
            ++lo;

        } else if (acc < sum) {
            if (hi == n-1) {
                break;
            }

            ++hi;
            acc += seq[hi];
        } else if (acc > sum) {
            if (lo == n-1) {
                break;
            }

            acc -= seq[lo];
            ++lo;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

