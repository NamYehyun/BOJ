#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int k;
    cin >> k;

    int curr_a = 1;
    int curr_b = 0;
    for (int i = 0; i < k; ++i) {
        int next_a = curr_b;
        int next_b = curr_b + curr_a;

        curr_a = next_a;
        curr_b = next_b;
    }

    cout << curr_a << ' ' << curr_b << endl;

    return EXIT_SUCCESS;
}

