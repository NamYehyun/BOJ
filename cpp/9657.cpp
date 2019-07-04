#include <iostream>
#include <vector>

using namespace std;


const bool SK = 1;
const bool CY = 0;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> memo(1001, CY);
    memo[1] = memo[3] = memo[4] = SK;

    for (int i = 5; i <= n; ++i) {
        memo[i] = !(memo[i-1] & memo[i-3] & memo[i-4]);
    }

    cout << ((memo[n] == SK) ? "SK" : "CY") << endl;

    return EXIT_SUCCESS;
}

