#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int ax, ay, az;
    cin >> ax >> ay >> az;

    int cx, cy, cz;
    cin >> cx >> cy >> cz;

    cout << cx - az << ' ' << cy / ay << ' ' << cz - ax << endl;

    return EXIT_SUCCESS;
}

