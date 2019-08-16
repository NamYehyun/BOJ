#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int s, t, d;
    cin >> s >> t >> d;

    cout << (d / (2*s)) * t << endl;

    return EXIT_SUCCESS;
}

