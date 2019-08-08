#include <algorithm>
#include <iostream>

using namespace std;


bool is_palindrome(string& str, int lo, int hi) {
    if (lo >= hi) {
        return true;
    }

    return (str[lo] == str[hi]) ? is_palindrome(str, lo+1, hi-1) : false;
}


bool is_palindrome(string& str) {
    const int len = str.length();
    return is_palindrome(str, 0, len-1);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string num;
        cin >> num;

        string rev = num;
        reverse(rev.begin(), rev.end());
        
        string sum = to_string(stoi(num) + stoi(rev));
        
        cout << (is_palindrome(sum) ? "YES" : "NO") << '\n';
    }

    return EXIT_SUCCESS;
}

