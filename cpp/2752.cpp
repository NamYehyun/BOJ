#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> seq(3);
    for (int i = 0; i < 3; ++i) {
        cin >> seq[i];
    }

    sort(seq.begin(), seq.end());

    for (const int& s: seq) {
        cout << s << ' ';
    }
    cout << endl;
    
    return EXIT_SUCCESS;
}

