#include <iostream>

using namespace std;


int main(void) {
    string num;
    int count[10];
    int six_or_nine = 0;
    
    cin >> num;
    for (int i = 0; i <= 9; ++i) {
        count[i] = 0;
    }

    int length = num.length();
    for (int i = 0; i < length; ++i) {
        int digit = (num[i] - '0');
        if (digit == 6 || digit == 9) {
            six_or_nine += 1;
        } else {
            count[digit] += 1;
        }
    }

    int max =  0;
    for (int i = 0; i <= 9; ++i) {
        if (max < count[i]) {
            max = count[i];
        }
    }

    int ans = (six_or_nine < 2 * max) ? max : (six_or_nine + 1) / 2;
    printf("%d\n", ans);

    return EXIT_SUCCESS;
}

