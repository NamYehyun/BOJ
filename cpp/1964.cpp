#include <iostream>

using namespace std;


const int DIV = 45678;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << (3*n*(n+1)/2 + (n+1)) % DIV << endl;

    return EXIT_SUCCESS;
}

