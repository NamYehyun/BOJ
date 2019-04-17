#include <iostream>

using namespace std;


const int E = 15;
const int S = 28;
const int M = 19;
const int MAX = E * S * M;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int e, s, m;
    cin >> e >> s >> m;

    int year;
    for (year = 1; year <= MAX; ++year) {
        bool cond_e = (year-1) % E == (e-1);
        bool cond_s = (year-1) % S == (s-1);
        bool cond_m = (year-1) % M == (m-1);
        if (cond_e && cond_s && cond_m) {
            break;
        }
    }

    cout << year << endl;

    return EXIT_SUCCESS;
}

