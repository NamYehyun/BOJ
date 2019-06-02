#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    vector<bool> is_square(100+1, false);
    for (int i = 1; i <= 10; ++i) {
        is_square[i*i] = true;
    }

    vector<int> cnt_square(100+1, 0);
    for (int i = 1; i <= 100; ++i) {
        cnt_square[i] = cnt_square[i-1] + (is_square[i] ? 1 : 0);
    }

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int n;
        cin >> n;

        cout << cnt_square[n] << '\n';
    }

    return EXIT_SUCCESS;
}

