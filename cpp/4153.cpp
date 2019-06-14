#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        vector<int> sides(3);
        cin >> sides[0] >> sides[1] >> sides[2];

        if (!sides[0] && !sides[1] && !sides[2]) {
            break;
        }

        sort(sides.begin(), sides.end());

        cout << (sides[2]*sides[2] == sides[0]*sides[0] + sides[1]*sides[1] ? "right" : "wrong") << '\n';
    }

    return EXIT_SUCCESS;
}

