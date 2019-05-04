#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int cnt = 0;
    int div = 1;
    int ans = 0;
    while (div <= n) {
        if (n % div == 0) {
            ++cnt;
        }

        if (cnt == k) {
            ans = div;
            break;
        }

        ++div;
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

