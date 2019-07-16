#include <algorithm>
#include <iostream>

using namespace std;


void half_adder(bool a, bool b, bool& sum, bool& carry_out) {
    sum = (a != b);
    carry_out = (a && b);
    
    return;
}


void full_adder(bool a, bool b, bool carry_in, bool& sum, bool& carry_out) {
    bool tmp1, tmp2, tmp3;

    half_adder(a, b, tmp1, tmp2);
    half_adder(carry_in, tmp1, sum, tmp3);
    
    carry_out = tmp2 || tmp3;

    return;
}


string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int len_a = a.length();
    int len_b = b.length();

    while (len_a < len_b) {
        a += '0';
        ++len_a;
    }

    while (len_b < len_a) {
        b += '0';
        ++len_b;
    }

    string c;
    bool is_zero = true;
    bool carry_in = 0, carry_out;
    for (int i = 0; i < len_a; ++i) {
        bool bit_a = (a[i] == '1');
        bool bit_b = (b[i] == '1');
        bool bit_c;

        full_adder(bit_a, bit_b, carry_in, bit_c, carry_out);

        if (bit_c) {
            c += '1';
            is_zero = false;
        } else {
            c += '0';
        }
        
        carry_in = carry_out;
    }

    if (carry_out) {
        c += '1';
        is_zero = false;
    }

    reverse(c.begin(), c.end());

    return (is_zero) ? "0" : c.substr(c.find('1'), c.length() - c.find('1'));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << add(a, b) << endl;

    return EXIT_SUCCESS;
}

