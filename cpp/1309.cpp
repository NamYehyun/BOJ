#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int prev, curr, next;

    prev = curr = 1;
    for (int i = 1; i <= n; ++i) {
        next = (2 * curr + prev) % 9901;

        prev = curr;
        curr = next;
    }

    cout << next << endl;

    return EXIT_SUCCESS;
}

