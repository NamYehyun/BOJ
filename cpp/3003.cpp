#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> orig {
        1, 1, 2, 2, 2, 8
    };

    for (int i = 0; i < 6; ++i) {
        int n;
        cin >> n;
        cout << orig[i] - n << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

