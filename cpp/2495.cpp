#include <iostream>

using namespace std;


int max_intv(string str) {
    int ans = 0;
    int cnt = 1;
    int length = str.length();
    for (int i = 1; i < length; ++i) {
        cnt = (str[i-1] == str[i]) ? (cnt + 1) : 1;
        ans = (ans < cnt) ? cnt : ans;
    }

    return ans;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 0; i < 3; ++i) {
        string line;
        cin >> line;
        cout << max_intv(line) << endl;
    }

    return EXIT_SUCCESS;
}

