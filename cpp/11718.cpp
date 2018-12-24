#include <iostream>
#include <string>

using namespace std;


int main(void) {
    string line;
    while (getline(cin, line)) {
        cout << line << endl;
    }

    return EXIT_SUCCESS;
}

