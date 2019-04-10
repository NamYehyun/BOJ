#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> brr(n);
    for (int i = 0; i < n; ++i) {
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    int acc = 0;
    for (int i = 0; i < n; ++i) {
        acc += (arr[i] * brr[n-1-i]);
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

