#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


void solve(int value, int idx, vector<int>& num, int num_add, int num_sub, int num_mul, int num_div, int& max_value, int& min_value) {
    if (num_add == 0 && num_sub == 0 && num_mul == 0 && num_div == 0) {
        if (max_value < value) {
            max_value = value;
        }

        if (min_value > value) {
            min_value = value;
        }
    }

    if (num_add > 0) solve(value + num[idx], idx+1, num, num_add-1, num_sub, num_mul, num_div, max_value, min_value);
    if (num_sub > 0) solve(value - num[idx], idx+1, num, num_add, num_sub-1, num_mul, num_div, max_value, min_value);
    if (num_mul > 0) solve(value * num[idx], idx+1, num, num_add, num_sub, num_mul-1, num_div, max_value, min_value);
    if (num_div > 0) solve(value / num[idx], idx+1, num, num_add, num_sub, num_mul, num_div-1, max_value, min_value);

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    int num_add, num_sub, num_mul, num_div;
    cin >> num_add >> num_sub >> num_mul >> num_div;

    int max_value = -INF, min_value = INF;

    solve(num[0], 1, num, num_add, num_sub, num_mul, num_div, max_value, min_value);

    cout << max_value << endl;
    cout << min_value << endl;
    return EXIT_SUCCESS;
}

