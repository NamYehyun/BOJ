#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int curr = 0;
    for (int i = 0; i < n; ++i) {
        cout << curr + 1;
        curr = (curr + 1) % 5;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

