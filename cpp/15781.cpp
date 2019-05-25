#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int max_x = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        max_x = max(x, max_x);
    }

    int max_y = 0;
    for (int i = 0; i < m; ++i) {
        int y;
        cin >> y;
        max_y = max(y, max_y);
    }

    cout << max_x + max_y << endl;

    return EXIT_SUCCESS;
}

