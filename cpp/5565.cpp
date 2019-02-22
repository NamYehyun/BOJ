#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int sum;
    cin >> sum;

    for (int i = 0; i < 9; ++i) {
        int x;
        cin >> x;

        sum -= x;
    }

    cout << sum << endl;
    
    return EXIT_SUCCESS;
}

