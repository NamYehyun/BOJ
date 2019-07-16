#include <iostream>
#include <vector>

using namespace std;


bool is_palindrome(string& str, int lo, int hi) {
    if (lo >= hi) {
        return true;
    }

    if (str[lo] == str[hi]) {
        return is_palindrome(str, lo+1, hi-1);
    } else {
        return false;
    }
}


bool is_palindrome(string str) {
    const int length = str.length();
    return is_palindrome(str, 0, length-1);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (found) {
                break;
            }

            for (int j = i + 1; j < n; ++j) {
                if (is_palindrome(words[i] + words[j])) {
                    found = true;
                    cout << words[i] + words[j] << '\n';
                    break;
                }

                if (is_palindrome(words[j] + words[i])) {
                    found = true;
                    cout << words[j] + words[i] << '\n';
                    break;
                }
            }
        }

        if (!found) {
            cout << 0 << '\n';
        }
    }

    return EXIT_SUCCESS;
}

