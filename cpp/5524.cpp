#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;

        int length = word.length();
        for (int i = 0; i < length; ++i) {
            if ('A' <= word[i] && word[i] <= 'Z') {
                cout << static_cast<char>(word[i] - 'A' + 'a');
            } else {
                cout << word[i];
            }
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

