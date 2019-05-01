#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string num;
    cin >> num;

    int length = num.length();
    vector<int> seq(length);

    bool zero = false;
    int acc = 0;
    for (int i = 0; i < length; ++i) {
        int num_i = static_cast<int>(num[i] - '0');
        seq[i] = num_i;

        if (num_i == 0) {
            zero = true;
        }

        acc += num_i;
    }

    if (!zero || (acc % 3 != 0)) {
        cout << -1 << endl;
        return EXIT_SUCCESS;
    }

    sort(seq.rbegin(), seq.rend());

    for (int s: seq) {
        cout << s;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

