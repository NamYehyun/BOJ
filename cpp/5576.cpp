#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> w(10);
    for (int i = 0; i < 10; ++i) {
        int score;
        cin >> score;
        w[i] = score;
    }

    vector<int> k(10);
    for (int i = 0; i < 10; ++i) {
        int score;
        cin >> score;
        k[i] = score;
    }

    sort(w.begin(), w.end());
    sort(k.begin(), k.end());

    cout << w[9] + w[8] + w[7] << ' ';
    cout << k[9] + k[8] + k[7] << endl;

    return EXIT_SUCCESS;
}

