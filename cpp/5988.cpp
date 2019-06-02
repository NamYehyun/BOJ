#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string num;
        cin >> num;

        int lsd = static_cast<int>(num[num.length()-1] - '0');
        cout << (lsd % 2 ? "odd" : "even") << '\n';
    }

    return EXIT_SUCCESS;
}

