#include <iostream>

using namespace std;


inline int max(int x, int y) {
    return (x > y) ? x : y;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    cout << max(b-a, c-b) - 1 << endl;

    return EXIT_SUCCESS;
}

