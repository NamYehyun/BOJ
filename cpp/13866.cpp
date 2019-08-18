#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = abs((a + b) - (c + d));
    ans = min(ans, abs((a + c) - (b + d)));
    ans = min(ans, abs((a + d) - (b + c)));

    cout << ans << endl;

    return EXIT_SUCCESS;
}

