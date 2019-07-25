#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string bin;
    cin >> bin;

    int len = bin.length();
    if (len % 3 == 1) {
        bin = "00" + bin;
        len = 2 + len;
    } else if (len % 3 == 2) {
        bin = "0" + bin;
        len = 1 + len;
    }

    for (int i = 0; i < len; i += 3) {
        int oct = 4*(bin[i] - '0') + 2*(bin[i+1] - '0') + 1*(bin[i+2] - '0');
        cout << oct;
    }
    cout << endl;
    
    return EXIT_SUCCESS;
}

