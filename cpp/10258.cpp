#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string bits;
        cin >> bits;

        const int length = bits.length();

        vector<bool> is_on(length);
        for (int i = 0; i < length; ++i) {
            is_on[i] = bits[i] == '0' ? false : true;
        }

        for (int i = 1; i < length; ++i) {
            if (is_on[i-1]) {
                is_on[i] = !is_on[i];                
            }
        }

        long long ans = 0;
        for (int i = 0; i < length; ++i) {
            ans = 2*ans + (is_on[i] ? 1 : 0);
        }

        cout << ans << '\n';
    }

    return EXIT_SUCCESS;
}

