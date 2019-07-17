#include <iostream>
#include <map>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> num_cookie;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;

        if (num_cookie.find(name) == num_cookie.end()) {
            num_cookie[name] = 0;
        }

        if (num_cookie[name] > i - num_cookie[name]) {
            ++cnt;
        }

        ++num_cookie[name];
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

