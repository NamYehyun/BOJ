#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (true) {
        long long n;
        cin >> n;
        if (n < 0) {
            break;
        }

        long long acc = 0;
        vector<long long> seq;
        for (long long i = 1; i < n; ++i) {
            if (n % i == 0) {
                acc += i;
                seq.push_back(i);
            }
        }

        if (acc == n) {
            cout << n << " = ";
            int size = seq.size();
            for (int i = 0; i < size; ++i) {
                cout << seq[i];
                if (i != size - 1) {
                    cout << " + ";
                }
            }
        } else {
            cout << n << " is NOT perfect.";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

