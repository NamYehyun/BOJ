#include <iostream>

using namespace std;


const int A = 1;
const int B = 2;
const int C = 3;


long long pow2(int n) {
    long long ret = 1;
    for (int i = 0; i < n; ++i) {
        ret *= 2;
    }

    return ret;
}


void move(int n, const int src, const int dst) {
    const int tmp = (A + B + C) - (src + dst);

    if (n == 1) {
        cout << src << ' ' << dst << '\n';
        return;
    }

    move(n-1, src, tmp);
    move(1, src, dst);
    move(n-1, tmp, dst);
    
    return;
}


void hanoi(int n) {
    move(n, A, C);
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    cout << pow2(n) - 1 << endl;
    hanoi(n);

    return EXIT_SUCCESS;
}

