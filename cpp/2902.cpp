#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    cin >> line;

    int length = line.length();
    for (int i = 0; i < length; ++i) {
        if ((i == 0) || (0 < i && line[i-1] == '-')) {
            cout << line[i];
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

