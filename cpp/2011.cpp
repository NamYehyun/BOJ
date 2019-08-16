#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string code;
    cin >> code;

    const int length = code.length();
    vector<int> memo(length, 0);

    memo[0] = 1;
    bool fail = (code[0] == '0');
    for (int i = 1; i < length; ++i) {
        int curr = static_cast<int>(code[i]-'0');
        int prev = static_cast<int>(code[i-1]-'0');

        if (curr == 0) {
            if (prev == 1 || prev == 2) {
                memo[i] += ((2 <= i) ? memo[i-2] : 1);
                memo[i] %= 1000000;
            } else {
                fail = true;
                break;
            }

        } else {
            if ((prev == 1) || (prev == 2 && curr <= 6)) {
                memo[i] += ((2 <= i) ? memo[i-2] : 1);
            }

            memo[i] += memo[i-1];
            memo[i] %= 1000000;
        }
    }

    cout << (fail ? 0 : memo[length-1]) << endl;

    return EXIT_SUCCESS;
}

