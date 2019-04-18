#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> nodes;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nodes.emplace_back(x, y);
    }

    sort(nodes.begin(), nodes.end());

    for (auto node: nodes) {
        cout << node.first << ' ' << node.second << '\n';
    }

    return EXIT_SUCCESS;
}

