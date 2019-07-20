#include <algorithm>
#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string word;
    cin >> word;

    string ans = word;
    const int length = word.length();
    for (int i = 0; i < length-2; ++i) {
        for (int j = i+1; j < length-1; ++j) {
            string a = word.substr(0, i+1);
            string b = word.substr(i+1, j-i);
            string c = word.substr(j+1);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            string w = a + b + c;

            if (ans > w) {
                ans = w;
            }
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

