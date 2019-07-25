#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral" << endl;
    } else if ((a + b + c == 180) && ((a == b) || (b == c) || (c == a))) {
        cout << "Isosceles" << endl;
    } else if (a + b + c == 180) {
        cout << "Scalene" << endl;
    } else {
        cout << "Error" << endl;
    }

    return EXIT_SUCCESS;
}

