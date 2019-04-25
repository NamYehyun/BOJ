#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> filename(n);
    for (int i = 0; i < n; ++i) {
        cin >> filename[i];
    }

    int length = filename[0].length();
    for (int idx = 0; idx < length; ++idx) {
        char c = filename[0][idx];

        bool same = true;
        for (int i = 1; i < n; ++i) {
            if (filename[i][idx] != c) {
                same = false;
                break;
            }
        }

        cout << (same ? c : '?');
    }
    cout << endl;

    return EXIT_SUCCESS;
}

