#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.setf(ios::fixed, ios::floatfield); cout.precision(1);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        int n;
        cin >> n;

        int credit = 0;
        double acc = 0.0;
        for (int i = 0; i < n; ++i) {
            int c;
            double g;
            cin >> c >> g;

            credit += c;
            acc += static_cast<double>(c) * g;
        }

        cout << credit << ' ' << acc / static_cast<double>(credit) << '\n';       
    }

    return EXIT_SUCCESS;
}

