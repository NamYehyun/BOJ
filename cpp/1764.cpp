#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<string> unnamed;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;

        unnamed.insert(name);
    }

    int cnt = 0;
    vector<string> nobody;
    for (int i = 0; i < m; ++i) {
        string name;
        cin >> name;

        if (unnamed.find(name) != unnamed.end()) {
            ++cnt;
            nobody.push_back(name);
        }
    }

    sort(nobody.begin(), nobody.end());

    cout << cnt << '\n';
    for (string name: nobody) {
        cout << name << '\n';
    }

    return EXIT_SUCCESS;
}

