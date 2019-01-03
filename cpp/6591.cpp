#include <iostream>
#include <string>

using namespace std;


const int MAX_N = 100;
const int MAX_D = 100;
const long long DIV = 10000000000;

class LongLong {
public:
    long long digits[MAX_D + 1];

    LongLong(long long n) {
        for (int i = 0; i < MAX_D; ++i) {
            digits[i] = 0;
        }

        digits[MAX_D] = n;
    }

    void mul(long long x) {
        long long carry = 0;
        for (int i = MAX_D; i > 0; --i) {
            long long curr = digits[i];
            curr *= x;

            digits[i] = curr % DIV + carry;
            carry = curr / DIV;
        }

        digits[0] *= x;

        return;
    }

    void div(long long x) {
        for (int i = 0; i < MAX_D; ++i) {
            long long curr = digits[i];

            digits[i] = curr / x;
            digits[i+1] += (curr % x) * DIV;
        }

        digits[MAX_D] /= x;

        return;
    }

    void print(void) {
        string str = "";
        for (int i = 0; i <= MAX_D; ++i) {
            str += to_string(digits[i]);
        }

        int start = 0;
        while(str[start] == '0') {
            ++start;
        }

        int length = str.length();
        for (int i = start; i < length; ++i) {
            printf("%c", str[i]);
        }

        printf("\n");

        return;
    }


};


int main(void) {
    while (true) {
        long long n, k;
        scanf("%lld%lld", &n, &k);

        if (n == 0 && k == 0) {
            break;
        }

        if (n - k < k) {
            k = n - k;
        }

        LongLong ll(1);
        for (int i = n; i >= n - k + 1; --i) {
            ll.mul(i);
        }

        for (int i = 1; i <= k; ++i) {
            ll.div(i);
        }

        ll.print();
    }

    return EXIT_SUCCESS;
}

