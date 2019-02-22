#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int cute = 0;
    for (int i = 0; i < n; ++i) {
        int vote;
        cin >> vote;

        if (vote == 1) {
            ++cute;
        } else {
            --cute;
        }
    }

    cout << (cute > 0 ? "Junhee is cute!" : "Junhee is not cute!") << endl;

    return EXIT_SUCCESS;
}

