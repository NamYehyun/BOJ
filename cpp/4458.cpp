#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_line;
    cin >> num_line;
    cin.ignore(1024, '\n');

    while (num_line--) {
        string line;
        getline(cin, line);

        if ('a' <= line[0] && line[0] <= 'z') {
            line[0] = line[0] - 'a' + 'A';
        }

        cout << line << '\n';
    }

    return EXIT_SUCCESS;
}

