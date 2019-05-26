#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    for (int i = 0; i < len_a; ++i) {
        if (a[i] == '6') {
            a[i] = '5';
        }
    }

    int len_b = b.length();
    for (int i = 0; i < len_b; ++i) {
        if (b[i] == '6') {
            b[i] = '5';
        }
    }

    cout << stoi(a) + stoi(b) << ' ';

    for (int i = 0; i < len_a; ++i) {
        if (a[i] == '5') {
            a[i] = '6';
        }
    }

    for (int i = 0; i < len_b; ++i) {
        if (b[i] == '5') {
            b[i] = '6';
        }
    }

    cout << stoi(a) + stoi(b) << endl;

    return EXIT_SUCCESS;
}

