#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string line;
    cin >> line;

    if (line.length() == 2) {
        int one = static_cast<int>(line[0] - '0');
        int two = static_cast<int>(line[1] - '0');
        cout << one + two << endl;
    } else if (line.length() == 3) {
        if (line[1] == '0') {
            int two = static_cast<int>(line[2] - '0');
            cout << 10 + two << endl;
        } else {
            int one = static_cast<int>(line[0] - '0');
            cout << one + 10 << endl;
        }
    } else {
        cout << 20 << endl;
    }

    return EXIT_SUCCESS;
}

