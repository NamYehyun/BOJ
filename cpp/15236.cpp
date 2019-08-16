#include <iostream>

using namespace std;


long long sigma(long long n) {
    return (n == 0) ? 0 : (n + sigma(n-1));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << sigma(n) * (n+2) << endl;

    return EXIT_SUCCESS;
}

