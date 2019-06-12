#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string word;
    cin >> word;

    int cnt = 0;
    for (const char& c: word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

