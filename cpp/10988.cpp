#include <iostream>

using namespace std;


bool is_palindrome_rec(string& str, int lo, int hi) {
    if (lo >= hi) {
        return true;
    }

    if (str[lo] == str[hi]) {
        return is_palindrome_rec(str, lo+1, hi-1);
    } else {
        return false;
    }
}


bool is_palindrome(string& str) {
    const int length = str.length();
    return is_palindrome_rec(str, 0, length-1);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string word;
    cin >> word;

    cout << is_palindrome(word) << endl;

    return EXIT_SUCCESS;
}

