#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int acc = 0;
    for (int i = 0; i < 5; ++i) {
        int n;
        cin >> n;
        acc += n;
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

