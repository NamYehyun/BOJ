#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;

    if ((a == b) && (b == c)) {
        cout << 10000 + a * 1000 << endl;
    } else if ((a == b) || (b == c) || (c == a)) {
        cout << 1000 + ((a == b) ? a : ((a == c) ? a : b)) * 100 << endl;
    } else {
        cout << ((a > b) ? (a > c ? a : c) : (b > c ? b : c)) * 100 << endl;
    }

    return EXIT_SUCCESS;
}

