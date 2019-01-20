#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> orig(n);
    for (int i = 0; i < n; ++i) {
        cin >> orig[i];
    }

    vector<int> result(orig);
    sort(result.begin(), result.end());

    for (int i = 0; i < n; ++i) {
        int num = orig[i];
        for (int j = 0; j < n; ++j) {
            if (result[j] == num) {
                cout << j << ' ';
                result[j] = -1;
                break;
            }
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

