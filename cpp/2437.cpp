#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());

    long long bound = 0;
    for (int i = 0; i < n; ++i) {
        if (static_cast<long long>(weight[i]) <= bound + 1) {
            bound += static_cast<long long>(weight[i]);
        } else {
            cout << bound + 1 << endl;
            return EXIT_SUCCESS;
        }
    }

    cout << bound + 1 << endl;
    
    return EXIT_SUCCESS;
}

