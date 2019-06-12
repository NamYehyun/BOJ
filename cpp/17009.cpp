#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int apples = 0;
    for (int i = 3; i >= 1; --i) {
        int shot;
        cin >> shot;
        apples += shot * i;
    }

    int bananas = 0;
    for (int i = 3; i >= 1; --i) {
        int shot;
        cin >> shot;
        bananas += shot * i;
    }

    char result = (apples > bananas) ? 'A'
                : (apples < bananas) ? 'B' : 'T';

    cout << result << endl;

    return EXIT_SUCCESS;
}

