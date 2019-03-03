#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int s = 0;
    for (int i = 0; i < 4; ++i) {
        int score;
        cin >> score;
        s += score;
    }

    int t = 0;
    for (int i = 0; i < 4; ++i) {
        int score;
        cin >> score;
        t += score;
    }

    cout << (s > t ? s : t) << endl;

    return EXIT_SUCCESS;
}

