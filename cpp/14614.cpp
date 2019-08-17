#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b;
    string c;
    cin >> a >> b >> c;

    cout << ((static_cast<int>(c[c.length()-1]-'0') % 2) ? (a ^ b) : a) << endl;

    return EXIT_SUCCESS;
}

