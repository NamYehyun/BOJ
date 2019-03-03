#include <iostream>

using namespace std;


inline int max(int x, int y) {
    return (x > y) ? x : y;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    cout << l - max(a/c + (a%c != 0), b/d + (b%d != 0)) << endl;

    return EXIT_SUCCESS;
}

