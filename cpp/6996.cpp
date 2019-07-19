#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string word_a, word_b;
        cin >> word_a >> word_b;

        vector<int> cnt_a('z'+1, 0);
        for (const char& c: word_a) {
            ++cnt_a[c];
        }

        vector<int> cnt_b('z'+1, 0);
        for (const char& c: word_b) {
            ++cnt_b[c];
        }

        bool anagram = true;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt_a[c] != cnt_b[c]) {
                anagram = false;
            }
        }

        if (anagram) {
            cout << word_a << " & " << word_b << " are anagrams." << '\n';
        } else {
            cout << word_a << " & " << word_b << " are NOT anagrams." << '\n';
        }
    }

    return EXIT_SUCCESS;
}

