#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x4 = (x1 == x2) ? x3
           : (x1 == x3) ? x2
           : (x2 == x3) ? x1 : 0;

    int y4 = (y1 == y2) ? y3
           : (y1 == y3) ? y2
           : (y2 == y3) ? y1 : 0;

    cout << x4 << ' ' << y4 << endl;

    return EXIT_SUCCESS;
}

