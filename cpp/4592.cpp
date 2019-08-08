#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        
        if (n == 0) {
            break;
        }

        int curr = 0;
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            cin >> curr;

            if (curr == prev) {
                continue;
            }

            cout << curr << ' ';
            
            prev = curr;
        }
        cout << '$' << '\n';
    }

    return EXIT_SUCCESS;
}

