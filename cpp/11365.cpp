#include <iostream>
#include <string>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        string line;
        getline(cin, line);

        if (line == "END") {
            break;
        }

        int length = line.length();
        for (int i = length-1; i >= 0; --i) {
            cout << line[i];
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

