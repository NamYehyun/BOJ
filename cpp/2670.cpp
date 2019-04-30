#include <iostream>
#include <iomanip>

using namespace std;


inline double max(double a, double b) {
    return (a > b ? a : b);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int size;
    cin >> size;

    double ans = 0.0;
    double acc = 1.0;
    for (int i = 0; i < size; ++i) {
        double num;
        cin >> num;

        acc *= num;

        ans = max(ans, acc);
        acc = max(acc, 1.0);
    }

    cout << fixed << setprecision(3) << ans << endl;
    
    return EXIT_SUCCESS;
}

