#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;


pair<bool, bool> half_adder(bool a, bool b) {
    return {a != b, a && b};
}


pair<bool, bool> full_adder(bool a, bool b, bool c_in) {
    bool s, c1, c2, sum, c_out;
    tie(s, c1) = half_adder(a, b);
    tie(sum, c2) = half_adder(s, c_in);

    c_out = c1 || c2;

    return {sum, c_out};
}


string add_bool(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    const int len_a = a.length();
    const int len_b = b.length();

    for (int i = 0; i < len_b - len_a; ++i) {
        a += '0';
    }

    for (int i = 0; i < len_a - len_b; ++i) {
        b += '0';
    }

    const int len = max(len_a, len_b);

    string c = "";
    bool carry_in = false;
    for (int i = 0; i < len; ++i) {
        bool digit_a = (a[i] == '1');
        bool digit_b = (b[i] == '1');

        bool digit_c, carry_out;

        tie(digit_c, carry_out) = full_adder(digit_a, digit_b, carry_in);

        c += (digit_c ? '1' : '0');
        carry_in = carry_out;
    }

    if (carry_in) {
        c += '1';
    }

    reverse(c.begin(), c.end());

    return c;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string n;
    cin >> n;

    string a = n + "0000";
    string b = n;

    cout << add_bool(a, b) << endl;

    return EXIT_SUCCESS;
}

