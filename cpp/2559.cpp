#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += seq[i];
    }

    int max_sum = sum;
    for (int i = k; i < n; ++i) {
        sum = sum - seq[i-k] + seq[i];
        max_sum = max(sum, max_sum);
    }

    cout << max_sum << endl;

    return EXIT_SUCCESS;
}

