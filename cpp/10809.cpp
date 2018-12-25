#include <iostream>

using namespace std;


int main(void) {
    string line;

    cin >> line;

    int count[26];
    for (int i = 0; i < 26; ++i) {
        count[i] = -1;
    }

    int length = line.length();
    for (int i = 0; i < length; ++i) {
        char c = line[i];
        if (count[c - 'a'] == -1) {
            count[c - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; ++i) {
        printf("%d ", count[i]);
    }

    return EXIT_SUCCESS;
}

