#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> seq(1001);

    int val = 1;
    int cnt = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (cnt == val) {
            ++val;
            cnt = 0;
        }

        seq[i] = val;
        ++cnt;
    }

    int a, b;
    cin >> a >> b;

    int acc = 0;
    for (int i = a; i <= b; ++i) {
        acc += seq[i];
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

