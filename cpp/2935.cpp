#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    char op;
    string a, b;
    cin >> a >> op >> b;

    int a_len = a.length();
    int b_len = b.length();

    if (a_len > b_len) {
        int tmp = a_len;
        a_len = b_len;
        b_len = tmp;
    }

    if (op == '+') {
        if (a_len == b_len) {
            cout << 2;
            for (int i = 1; i < a_len; ++i) {
                cout << 0;
            }
        } else {
            cout << 1;
            for (int i = 1; i < b_len - a_len; ++i) {
                cout << 0;
            }
            cout << 1;
            for (int i = 1; i < a_len; ++i) {
                cout << 0;
            }
        }
    } else {
        cout << 1;
        for (int i = 1; i < a_len + b_len - 1; ++i) {
            cout << 0;
        }
    }

    cout << endl;
    
    return EXIT_SUCCESS;
}

