#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int day;
    cin >> day;

    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        int car;
        cin >> car;

        if (day == car) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

