#include <iostream>
#include <sstream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string line;
        cin >> line;
        if (line == "P=NP") {
            cout << "skipped" << '\n';
            continue;
        }

        stringstream ss(line);
        int one, two;
        char plus;

        ss >> one >> plus >> two;

        cout << one + two << '\n';
    }

    return EXIT_SUCCESS;
}

