#include <iostream>
#include <vector>

using namespace std;


inline int pow10(int x) {
    int pow = 1;
    for (int i = 0; i < x; ++i) {
        pow *= 10;
    }

    return pow;
}


inline string swap(string str, int i, int j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;

    return str;
}


int solve(string num, int k) {
    // cout << "solve(" << num << "," << k << endl;
    if (k == 0) {
        return stoi(num);
    }

    int len = num.length();
    if (len == 2) {
        return solve(swap(num, 0, 1), k-1);
    }

    int max_digit = -1;
    for (int i = 0; i < len; ++i) {
        int digit = static_cast<int>(num[i] - '0');
        if (max_digit < digit) {
            max_digit = digit;
        }
    }

    vector<int> max_idx;
    for (int i = 0; i < len; ++i) {
        if (static_cast<int>(num[i] - '0') == max_digit) {
            max_idx.push_back(i);
        }
    }

    int max_sol = ((max_idx[0] == 0) && (max_idx.size() > 1)) ? stoi(num.substr(1, len-1)) : -1 ;
    if (max_idx[0] == 0) {
        max_sol = max(max_sol, solve(num.substr(1, len-1), k));
    }

    for (int idx: max_idx) {
        if (idx == 0) {
            continue;
        }

        int sol = solve(swap(num, 0, idx).substr(1, len-1), k-1);
        if (max_sol < sol) {
            max_sol = sol;
        }
    }

    if (max_sol == -1) {
        return max_digit*pow10(len-1) + solve(num.substr(1, len-1), k);
    } else {
        return max_digit*pow10(len-1) + max_sol;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string num;
    cin >> num;

    int k;
    cin >> k;

    int length = num.length();
    if ((length == 1) || (length == 2 && num[1] == '0')) {
        cout << -1 << endl;
    } else {
        cout << solve(num, k) << endl;
    }


    return EXIT_SUCCESS;
}

