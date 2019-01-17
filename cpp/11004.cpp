#include <algorithm>
#include <iostream>

using namespace std;


const int MAX_N = 5000000;

int n, k;
int arr[MAX_N];


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    --k;
    nth_element(arr, arr + k, arr + n);

    cout << arr[k] << '\n';

    return EXIT_SUCCESS;
}

