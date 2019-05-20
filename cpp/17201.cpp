#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    string line;
    cin >> line;

    bool connected = true;
    for (int i = 1; i < 2*n; ++i) {
        if (line[i] == line[i-1]) {
            connected = false;
        }
    }

    cout << (connected ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}

