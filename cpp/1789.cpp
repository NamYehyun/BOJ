#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long sum;
    cin >> sum;

    long long cnt = 1;
    while (true) {
        if (sum < cnt*(cnt+1)/2) {
            break;
        }
        ++cnt;
    }

    cout << cnt-1 << endl;

    return EXIT_SUCCESS;
}

