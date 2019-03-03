#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long n;
    cin >> n;

    int acc = 0;
    int bound = 0;
    while (true) {
        int cnt = n - bound;
        if (cnt < 0) {
            break;
        }

        acc += cnt;
        
        bound = 10*bound + 9;
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

