#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int acc = 0;
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        acc += ((m + 1) / 2);
    }

    cout << (n <= acc ? "YES" : "NO") << endl;

    return EXIT_SUCCESS;
}

