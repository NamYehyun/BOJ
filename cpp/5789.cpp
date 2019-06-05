#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string line;
        cin >> line;

        int length = line.length();
        int left = length/2 -1;
        int right = length/2;

        cout << (line[left] == line[right] ? "Do-it" : "Do-it-Not") << "\n";
    }

    return EXIT_SUCCESS;
}

