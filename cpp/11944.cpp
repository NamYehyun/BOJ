#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int len = 0; 
    string n_str = to_string(n);
    int n_len = n_str.length();
    for (int i = 0; i < n; ++i) {
        len += n_len;
        if (len > m) {
            cout << n_str.substr(0, n_len - (len - m));
            break;
        } else {
            cout << n_str;
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}

