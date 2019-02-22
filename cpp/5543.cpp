#include <iostream>

using namespace std;


inline int min(int a, int b) {
    return (a < b) ? a : b;
}


inline int min(int a, int b, int c) {
    return min(a, min(b, c));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int x, y;
    cin >> x >> y;

    cout << min(a, b, c) + min(x, y) - 50 << endl;

    return EXIT_SUCCESS;
}

