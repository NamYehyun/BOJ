#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int cost;
    cin >> cost;

    int rest = 1000 - cost;
    int change[6] = {500, 100, 50, 10, 5, 1};

    int cnt = 0;
    for (int i = 0; i < 6; ++i) {
        cnt += rest / change[i];
        rest = rest % change[i];
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

