#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


const int MAX = 1000000;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    sort(seq.rbegin(), seq.rend());

    for (const int& s: seq) {
        cout << s << '\n';
    }

    return EXIT_SUCCESS;
}

