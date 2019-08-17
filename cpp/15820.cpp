#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int nsample, nsystem;
    cin >> nsample >> nsystem;

    bool sample_ok = true;
    for (int i = 0; i < nsample; ++i) {
        long long a, b;
        cin >> a >> b;

        if (a != b) {
            sample_ok = false;
        }
    }

    bool system_ok = true;
    for (int i = 0; i < nsystem; ++i) {
        long long a, b;
        cin >> a >> b;

        if (a != b) {
            system_ok = false;
        }
    }

    if (sample_ok) {
        if (system_ok) {
            cout << "Accepted" << endl;
        } else {
            cout << "Why Wrong!!!" << endl;
        }
    } else {
        cout << "Wrong Answer" << endl;
    }

    return EXIT_SUCCESS;
}

