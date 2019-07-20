#include <iostream>

using namespace std;


bool is_palindrome(string& str, int lo, int hi) {
    if (lo >= hi) {
        return true;
    }

    return (str[lo] == str[hi]) ? is_palindrome(str, lo+1, hi-1) : false;
}


bool is_palindrome(string str) {
    const int length = str.length();

    for (char& c: str) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }

    return is_palindrome(str, 0, length-1);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;

    char c;
    while (cin.get(c) && c != '\n');

    while (num_test--) {
        string line;
        getline(cin, line);

        cout << (is_palindrome(line) ? "Yes" : "No") << '\n';
    }

    return EXIT_SUCCESS;
}

