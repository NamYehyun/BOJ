#include <iostream>

using namespace std;


int construct(int n) {
    int sum = n;

    while (true) {
        if (n == 0) {
            break;
        }

        sum += n % 10;
        n /= 10;
    }

    return sum;
}


int main(void) {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = n; i >= 1; --i) {
        if (construct(i) == n) {
            ans = i;
        }
    }

    cout << ans << endl;
    
    return EXIT_SUCCESS;
}

