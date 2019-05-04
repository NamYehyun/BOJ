#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int max_val = 0;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        int val;
        if ((a == b) && (b == c)) {
            val = 10000 + a * 1000;
        } else if ((a == b) || (b == c) || (c == a)) {
            val = 1000 + ((a == b) ? a : ((a == c) ? a : b)) * 100;
        } else {
            val = ((a > b) ? (a > c ? a : c) : (b > c ? b : c)) * 100;
        }

        max_val = (max_val < val) ? val : max_val;
    }

    cout << max_val << endl;

    return EXIT_SUCCESS;
}

