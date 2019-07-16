#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;

    char c;
    while (cin.get(c) && c != '\n');

    while (num_test--) {
        string name;
        getline(cin, name);

        cout << "god";

        int first = true;
        for (const char& c: name) {
            if (!first && (c != ' ')) {
                cout << c;
            }

            if (c == ' ') {
                first = false;
            }
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

