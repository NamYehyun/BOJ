#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << min(a + d, b + c) << endl;

    return EXIT_SUCCESS;
}

