#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


const int MAX = 100000;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int query;
        cin >> query;
        cout << binary_search(num.begin(), num.end(), query) << '\n';
    }

    return EXIT_SUCCESS;
}

