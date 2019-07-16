#include <iostream>

using namespace std;


long long pow2(int i) {
    return (i == 0) ? 1 : 2 * pow2(i-1);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int x = pow2(n) + 1;
    cout << x * x << endl;

    return EXIT_SUCCESS;
}

