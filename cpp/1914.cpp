#include <iostream>
#include <vector>

using namespace std;


class BigInt {
public:
    const int length = 100;
    vector<char> rep;

    BigInt(int n) {
        rep.resize(length, '0');

        int idx = 0;
        while (n) {
            rep[idx] = static_cast<char>((n % 10) + '0');
            n /= 10;
            ++idx;
        }
    }

    void times(int n) {
        int carry = 0;
        for (int i = 0; i < length; ++i) {
            int digit = static_cast<int>(rep[i] - '0');
            int new_digit = (digit * n) % 10;

            rep[i] = static_cast<char>(new_digit + carry + '0');
            carry = (digit * n) / 10;
        }

        return;
    }

    void minus(int n) {
        rep[0] = static_cast<char>(static_cast<int>(rep[0] - '0') - n + '0');

        return;
    }

    string value(void) {
        int idx = length-1;
        while (rep[idx] == '0') {
            --idx;
        }

        string val = "";
        while (idx >= 0) {
            val += rep[idx];
            --idx;
        }

        return val;
    }
};


class Hanoi {
public:
    int size;

    Hanoi(int _size): size(_size) {}

    void move(int n, int src, int dst, int tmp) {
        if (n == 1) {
            cout << src << ' ' << dst << '\n';
            return;
        }

        move(n-1, src, tmp, dst);
        move(1, src, dst, tmp);
        move(n-1, tmp, dst, src);

        return;
    }

    void solve(void) {
        move(size, 1, 3, 2);

        return;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    BigInt one(1);
    
    for (int i = 0; i < n; ++i) {
        one.times(2);
    }

    one.minus(1);
    
    cout << one.value() << endl;

    if (n <= 20) {
        Hanoi hanoi(n);
        hanoi.solve();
    }

    return EXIT_SUCCESS;
}

