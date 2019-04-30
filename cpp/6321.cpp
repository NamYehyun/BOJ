#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << "String #" << i << '\n';

        string word;
        cin >> word;

        int length = word.length();
        for (int idx = 0; idx < length; ++idx) {
            if (word[idx] == 'Z') {
                cout << 'A';
            } else {
                cout << static_cast<char>(word[idx] + 1);
            }
        }
        cout << endl;
        cout << endl;
    }

    return EXIT_SUCCESS;
}

