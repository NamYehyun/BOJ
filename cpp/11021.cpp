#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << i << ": " << a + b << "\n";
    }

    return EXIT_SUCCESS;
}

