#include <algorithm>
#include <iostream>

using namespace std;


const int INF = 0x7f7f7f7f;


inline int min(int a, int b) {
    return (a < b) ? a : b;
}


inline int min(int a, int b, int c) {
    return min(a, min(b, c));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int min_pack = INF;
    int min_unit = INF;
    for (int i = 0; i < m; ++i) {
        int pack, unit;
        cin >> pack >> unit;
        min_pack = min(pack, min_pack);
        min_unit = min(unit, min_unit);
    }

    int x = ((n + 5) / 6) * min_pack;
    int y = n * min_unit;
    int z = (n / 6) * min_pack + (n % 6) * min_unit;

    cout << min(x, y, z) << endl;

    return EXIT_SUCCESS;
}

