#include <iostream>

using namespace std;


inline int min(int a, int b) {
    return (a < b) ? a : b;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << min(min(x, w-x), min(y, h-y)) << endl;

    return EXIT_SUCCESS;
}

