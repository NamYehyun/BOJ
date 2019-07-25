#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<bool> exists(21, false);

    int num_query;
    cin >> num_query;
    while (num_query--) {
        string op;
        cin >> op;
        if (op == "add") {
            int x;
            cin >> x;
            exists[x] = true;
        } else if (op == "remove") {
            int x;
            cin >> x;
            exists[x] = false;
        } else if (op == "check") {
            int x;
            cin >> x;
            cout << exists[x] << '\n';
        } else if (op == "toggle") {
            int x;
            cin >> x;
            exists[x] = !exists[x];
        } else if (op == "all") {
            for (int i = 0; i <= 20; ++i) {
                exists[i] = true;
            }
        } else if (op == "empty") {
            for (int i = 0; i <= 20; ++i) {
                exists[i] = false;
            }
        }
    }

    return EXIT_SUCCESS;
}

