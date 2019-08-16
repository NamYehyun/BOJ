#include <algorithm>
#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b, s = "";
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int len_a = a.length();
    int len_b = b.length();

    for (int i = 0; i < len_b-len_a; ++i) {
        a += '0';
    }

    for (int i = 0; i < len_a-len_b; ++i) {
        b += '0';
    }

    int len = max(len_a, len_b);

    int carry = 0;
    for (int i = 0; i < len; ++i) {
        int digit_a = static_cast<int>(a[i] - '0');
        int digit_b = static_cast<int>(b[i] - '0');

        int sum = digit_a + digit_b + carry;

        s += static_cast<char>((sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry != 0) {
        s += static_cast<char>(carry + '0');
    }

    reverse(s.begin(), s.end());

    cout << s << endl;

    return EXIT_SUCCESS;
}

