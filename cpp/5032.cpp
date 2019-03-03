#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int e, f, c;
    cin >> e >> f >> c;

    int ans = 0;
    int empty = e + f;
    int cost = c;
    while (true) {
        if (empty < cost) {
            break;
        }

        ans += (empty / cost);
        empty = (empty % cost) + (empty / cost);
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

