#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            int mul = 1;
            while (true) {
                if (n < i * mul) {
                    break;
                }
                
                if (prime[i * mul]) {
                    prime[i * mul] = false;
                    ++cnt;
                }

                if (cnt == k) {
                    cout << i * mul << endl;
                    return EXIT_SUCCESS;
                }

                ++mul;
            }
        }
    }

    return EXIT_SUCCESS;
}

