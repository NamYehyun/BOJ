#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int h, m, s;
    cin >> h >> m >> s;

    int cost;
    cin >> cost;

    s += cost;
    if (s >= 60) {
        m += (s / 60);
        s %= 60;
    }

    if (m >= 60) {
        h += (m / 60);
        m %= 60;
    }

    if (h >= 24) {
        h %= 24;
    }

    cout << h << ' ' << m << ' ' << s << endl;

    return EXIT_SUCCESS;
}

