#include <iostream>

using namespace std;


int main(void) {
    string word;

    cin >> word;

    int count = 0;
    int length = word.length();
    for (int i = 0; i < length; ++i) {
        ++count;
        if (word[i] == 'c') {
            if (i+1 < length && (word[i+1] == '=' || word[i+1] == '-')) {
                i += 1;
            }
        } else if(word[i] == 'd') {
            if (i+2 < length && word[i+1] == 'z' && word[i+2] == '=') {
                i += 2;
            } else if (i+1 < length && word[i+1] == '-') {
                i += 1;
            }
        } else if (word[i] == 'l') {
            if (i+1 < length && word[i+1] == 'j') {
                i += 1;
            }
        } else if (word[i] == 'n') {
            if (i+1 < length && word[i+1] == 'j') {
                i += 1;
            }
        } else if (word[i] == 's') {
            if (i+1 < length && word[i+1] == '=') {
                i += 1;
            }
        } else if (word[i] == 'z') {
            if (i+1 < length && word[i+1] == '=') {
                i += 1;
            }
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

