#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    for (int i = 1; i <= num_test; ++i) {
        int n;
        cin >> n;

        vector<int> score(n);
        for (int i = 0; i < n; ++i) {
            cin >> score[i];
        }

        sort(score.rbegin(), score.rend());

        int max_gap = 0;
        for (int i = 1; i < n; ++i) {
            int gap = score[i-1] - score[i];
            max_gap = max(gap, max_gap);
        }

        cout << "Class " << i << '\n';
        cout << "Max " << score[0] << ", Min " << score[n-1] << ", Largest gap " << max_gap << '\n';
    }

    return EXIT_SUCCESS;
}

