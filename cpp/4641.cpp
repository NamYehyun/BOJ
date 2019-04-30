#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        int x;
        cin >> x;

        if (x == -1) {
            break;
        }

        vector<int> seq;
        seq.push_back(x);

        while (true) {
            int n;
            cin >> n;

            if (n == 0) {
                break;
            }

            seq.push_back(n);
        }

        int cnt = 0;
        int length = seq.size();
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if (seq[i] == 2 * seq[j]) {
                    ++cnt;
                }
            }
        }

        cout << cnt << endl;
    }

    return EXIT_SUCCESS;
}

