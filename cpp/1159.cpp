#include <iostream>
#include <vector>

using namespace std;


inline int index_of(string name) {
    return static_cast<int>(name[0]) - 'a';
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> count(26, 0);
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;

        ++count[index_of(name)];
    }

    int c = 0;
    for (int i = 0; i < 26; ++i) {
        if (5 <= count[i]) {
            ++c;
            cout << static_cast<char>(i + 'a');
        }
    }

    if (c == 0) {
        cout << "PREDAJA";
    }

    cout << endl;

    return EXIT_SUCCESS;
}

