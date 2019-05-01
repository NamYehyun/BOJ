#include <iostream>
#include <vector>

using namespace std;


inline bool is_num(char c) {
    return ('0' <= c && c <= '9');
}


inline int to_num(char c) {
    return static_cast<int>(c - '0');
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string expr;
    cin >> expr;

    int n = 0;
    vector<int> num;
    vector<char> op;
    int length = expr.length();
    for (int i = 0; i < length; ++i) {
        if (is_num(expr[i])) {
            n = 10*n + to_num(expr[i]);
        } else {
            num.push_back(n);
            op.push_back(expr[i]);

            n = 0;
        }
    }
    num.push_back(n);

    int acc = num[0];
    bool minus = false;
    int size = num.size();
    for (int i = 1; i < size; ++i) {
        if (op[i-1] == '-') {
            minus = true;
        }

        if (minus) {
            acc -= num[i];
        } else {
            acc += num[i];
        }
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

