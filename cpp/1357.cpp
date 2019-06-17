#include <algorithm>
#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string x, y;
    cin >> x >> y;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    string sum = to_string(stoi(x) + stoi(y));
    reverse(sum.begin(), sum.end());

    cout << stoi(sum) << endl;

    return EXIT_SUCCESS;
}

