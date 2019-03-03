#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> friends(n+1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    set<int> invite;
    for (int f: friends[1]) {
        invite.insert(f);

        for (int ff: friends[f]) {
            if (ff == 1) {
                continue;
            }

            invite.insert(ff);
        }
    }

    cout << invite.size() << endl;

    return EXIT_SUCCESS;
}

