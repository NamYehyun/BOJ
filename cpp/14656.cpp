#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    for (int pos = 1; pos <= n; ++pos) {
        int id;
        cin >> id;
        if (id != pos) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

