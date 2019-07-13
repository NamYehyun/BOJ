#include <iostream>
#include <vector>

using namespace std;


int main (void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> golomb;
    golomb.push_back(0);

    int acc = 0;
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        golomb.push_back(1 + golomb[i-golomb[golomb[i-1]]]);

        acc += golomb[i];

        if (n <= acc) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;

}

