#include <iostream>

using namespace std;


string rot13(string str) {
    for (char& c: str) {
        if ('a' <= c && c <= 'z') {
            c = ((c-'a') + 13) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            c = ((c-'A') + 13) % 26 + 'A';
        }
    }

    return str;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string line;
    getline(cin, line);

    cout << rot13(line) << endl;

    return EXIT_SUCCESS;
}

