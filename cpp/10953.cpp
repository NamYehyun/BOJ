#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        char comma;

        cin >> a >> comma >> b;

        cout << a + b << '\n';
    }

    return EXIT_SUCCESS;
}

