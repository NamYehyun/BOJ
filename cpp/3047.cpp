#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> abc(3);
    for (int i = 0; i < 3; ++i) {
        cin >> abc[i];
    }

    sort(abc.begin(), abc.end());

    string word;
    cin >> word;

    int len = word.length();
    for (int i = 0; i < len; ++i) {
        cout << abc[static_cast<int>(word[i] - 'A')] << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

