#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> less_than;
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        less_than.push_back((op == '<') ? true : false);
    }

    vector<int> seq;
    for (int i = 0; i <= n; ++i) {
        seq.push_back(9-i);
    }

    do {
        bool found = true;
        for (int i = 1; i <= n; ++i) {
            if ((seq[i-1] < seq[i]) != less_than[i-1]) {
                found = false;
            }
        }

        if (found) {
            break;
        }
    } while (prev_permutation(seq.begin(), seq.end()));

    for (const int& s: seq) {
        cout << s;
    }
    cout << endl;

    seq.clear();
    for (int i = 0; i <= n; ++i) {
        seq.push_back(i);
    }

    do {
        bool found = true;
        for (int i = 1; i <= n; ++i) {
            if ((seq[i-1] < seq[i]) != less_than[i-1]) {
                found = false;
            }
        }

        if (found) {
            break;
        }
    } while (next_permutation(seq.begin(), seq.end()));

    for (const int& s: seq) {
        cout << s;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

