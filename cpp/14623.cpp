#include <iostream>

using namespace std;


long long to_dec(string bin) {
    long long ret = 0;
    for (const auto& b: bin) {
        ret *= 2;
        ret += (b == '1' ? 1 : 0);
    }

    return ret;
}


string to_bin(long long dec) {
    string ret = "";
    while (dec > 0) {
        ret = (dec % 2 == 1 ? '1' : '0') + ret;
        dec /= 2;
    }

    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << to_bin(to_dec(a) * to_dec(b)) << endl;

    return EXIT_SUCCESS;
}

