#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int l, p;
    cin >> l >> p;

    for (int i = 0; i < 5; ++i) {
        int num;
        cin >> num;
        cout << num - l * p << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

