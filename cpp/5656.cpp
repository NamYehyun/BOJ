#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int c = 1;
    while (true) {
        int a, b;
        string op;
        cin >> a >> op >> b;

        if (op == ">") {
            cout << "Case " << c << ": " << (a > b ? "true" : "false") << '\n';
        } else if (op == ">=") {
            cout << "Case " << c << ": " << (a >= b ? "true" : "false") << '\n';
        } else if (op == "<") {
            cout << "Case " << c << ": " << (a < b ? "true" : "false") << '\n';
        } else if (op == "<=") {
            cout << "Case " << c << ": " << (a <= b ? "true" : "false") << '\n';
        } else if (op == "==") {
            cout << "Case " << c << ": " << (a == b ? "true" : "false") << '\n';
        } else if (op == "!=") {
            cout << "Case " << c << ": " << (a != b ? "true" : "false") << '\n';
        } else {
            break;
        }

        ++c;
    }

    return EXIT_SUCCESS;
}

