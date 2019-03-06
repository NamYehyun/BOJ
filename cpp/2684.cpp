#include <iostream>

using namespace std;


const int X = 0;
const int T = 1;
const int H = 2;
const int TT = 11;
const int TH = 12;
const int HT = 21;
const int HH = 22;
const int TTT = 111;
const int TTH = 112;
const int THT = 121;
const int THH = 122;
const int HTT = 211;
const int HTH = 212;
const int HHT = 221;
const int HHH = 222;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string line;
        cin >> line;

        int state = X;
        int count[300] = {};

        for (int i = 0; i < 40; ++i) {
            state = (10 * state + (line[i] == 'T' ? T : H)) % 1000;
            ++count[state];
        }

        cout << count[TTT] << ' '
            << count[TTH] << ' '
            << count[THT] << ' '
            << count[THH] << ' '
            << count[HTT] << ' '
            << count[HTH] << ' '
            << count[HHT] << ' '
            << count[HHH] << '\n';
    }

    return EXIT_SUCCESS;
}

