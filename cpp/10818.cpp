#include <iostream>

using namespace std;


const int INF = 0x7f7f7f7f;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int min = INF;
    int max = -INF;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (min > x) {
            min = x;
        }

        if (max < x) {
            max = x;
        }
    }

    cout << min << ' ' << max << endl;

    return EXIT_SUCCESS;
}

