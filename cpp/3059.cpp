#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        string str;
        cin >> str;
        
        vector<bool> exists('Z'-'A'+1, false);
        for (const char& c: str) {
            exists[static_cast<int>(c-'A')] = true;
        }

        int acc = 0;
        for (int i = 0; i <= static_cast<int>('Z'-'A'); ++i) {
            if (!exists[i]) {
                acc += static_cast<int>('A') + i;
            }
        }

        cout << acc << '\n';
    }

    return EXIT_SUCCESS;
}

