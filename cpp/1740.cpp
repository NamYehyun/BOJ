#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    long long t = 1;
    long long acc = 0;
    for (int i = 0; i < 50; ++i) {
        acc += t * (1LL & n);
        n /= 2;
        t *= 3;        
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

