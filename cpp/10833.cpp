#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int acc = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        acc += (b % a);
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

