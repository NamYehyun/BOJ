#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string oct;
    cin >> oct;

    int length = oct.length();
    for (int i = 0; i < length; ++i) {
        int digit = static_cast<int>(oct[i] - '0');
        string output = "000";

        for (int j = 2; j >= 0; --j) {
            output[j] = static_cast<char>(digit % 2 + '0');
            digit /= 2;
        }

        if (i == 0) {
            int idx = 0;
            while ((idx < 3) && (output[idx] == '0')) {
                ++idx;
            }
            cout << ((idx < 3) ? output.substr(idx, 3-idx) : "0");
        } else {
            cout << output;
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}

