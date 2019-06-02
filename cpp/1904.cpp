#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    
    int prev, curr, next;
    prev = 0;
    curr = 1;
    for (int i = 1; i <= n; ++i) {
        next = (prev + curr) % 15746;

        prev = curr;
        curr = next;
    }

    cout << next << endl;

    return EXIT_SUCCESS;
}

