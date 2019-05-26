#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string line;
    cin >> line;

    int cnt_joi = 0;
    int cnt_ioi = 0;
    int length = line.length();
    for (int i = 0; i <= length-3; ++i) {
        cnt_joi += (line[i] == 'J' && line[i+1] == 'O' && line[i+2] == 'I');
        cnt_ioi += (line[i] == 'I' && line[i+1] == 'O' && line[i+2] == 'I');
    }

    cout << cnt_joi << endl << cnt_ioi << endl;

    return EXIT_SUCCESS;
}

