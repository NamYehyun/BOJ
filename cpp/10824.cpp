#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    long long one = stol(a + b);
    long long two = stol(c + d);

    cout << one + two << endl;

    return EXIT_SUCCESS;
}

