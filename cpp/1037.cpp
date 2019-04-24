#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> divisor(n);
    for (int i = 0; i < n; ++i) {
        cin >> divisor[i];
    }

    sort(divisor.begin(), divisor.end());

    cout << divisor[0] * divisor[n-1] << endl;

    return EXIT_SUCCESS;
}

