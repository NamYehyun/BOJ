#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    string ans = "";
    while (n) {
        ans = static_cast<char>((n % 9) + '0') + ans;
        n /= 9;
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

