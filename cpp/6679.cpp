#include <iostream>

using namespace std;


int transform(int num, int base) {
    int ret = 0;
    while (num) {
        ret += num % base;
        num /= base;
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int num = 1000; num <= 9999; ++num) {
        if (transform(num, 10) == transform(num, 12) && transform(num, 10) == transform(num, 16)) {
            cout << num << endl;
        }
    }

    return EXIT_SUCCESS;
}

