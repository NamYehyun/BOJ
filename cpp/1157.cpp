#include <iostream>

using namespace std;


int alpha_to_index(char a) {
    if ('a' <= a && a <= 'z') {
        return a - 'a';
    } else {
        return a - 'A';
    }
}


char index_to_alpha(int i) {
    return 'A' + i;
}


int main(void) {
    string word;
    cin >> word;

    int count[26];
    for (int i = 0; i < 26; ++i) {
        count[i] = 0;
    }

    int length = word.length();
    for (int i = 0; i < length; ++i) {
        count[alpha_to_index(word[i])] += 1;
    }

    int idx = -1;
    int max = -1;
    for (int i = 0; i < 26; ++i) {
        if (max < count[i]) {
            idx = i;
            max = count[i];
        }
    }

    bool unique = true;
    for (int i = 0; i < 26; ++i) {
        if (i != idx && count[i] == max) {
            unique = false;
        }
    }

    if (unique) {
        printf("%c\n", index_to_alpha(idx));
    } else {
        printf("?\n");
    }

    return EXIT_SUCCESS;
}

