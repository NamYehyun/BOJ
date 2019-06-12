#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    bool ans = false;
    for (int i = 0; i <= 30; ++i) {
        if (n == (1 << i)) {
            ans = true;
            break;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

