#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string A;
    cin >> A;

    long long a_sum = 0;
    for (const auto& a: A) {
        a_sum += static_cast<long long>(a - '0');
    }

    string B;
    cin >> B;
    
    long long b_sum = 0;
    for (const auto& b: B) {
        b_sum += static_cast<long long>(b - '0');
    }

    cout << a_sum * b_sum << endl;

    return EXIT_SUCCESS;
}

