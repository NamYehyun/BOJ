#include <iostream>

using namespace std;


bool is_group_word(string word) {
    bool appeared[26];
    for (int i = 0; i < 26; ++i) {
        appeared[i] = false;
    }

    int length = word.length();
    for (int i = 0; i < length; ++i) {
        if (!appeared[word[i] - 'a']) {
            appeared[word[i] - 'a'] = true;
        } else {
            if (word[i-1] == word[i]) {
                // do nothing
            } else {
                return false;
            }
        }
    }

    return true;
}


int main(void) {
    int n;

    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        if (is_group_word(word)) {
            ++count;
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

