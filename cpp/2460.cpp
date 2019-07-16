#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int curr = 0;
    int peak = 0;
    for (int i = 0; i < 10; ++i) {
        int sub, add;
        cin >> sub >> add;

        curr = curr - sub + add;

        if (peak < curr) {
            peak = curr;
        }
    }

    cout << peak << endl;

    return EXIT_SUCCESS;
}

