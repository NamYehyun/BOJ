#include <iostream>
#include <vector>

using namespace std;


const int num_alph = static_cast<int>('z' - 'a' + 1);


inline int index_of(char c) {
    return static_cast<int>(c - 'a');
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string word;
    cin >> word;

    vector<int> count(num_alph, 0);
    for (char w: word) {
        ++count[index_of(w)];
    }

    for (int c: count) {
        cout << c << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

