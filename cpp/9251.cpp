#include <iostream>

using namespace std;


const int MAX_LEN = 1000;

string str1, str2;
int memo[MAX_LEN + 1][MAX_LEN + 1];


int max(int a, int b) {
    return (a > b) ? a : b;
}


int lcs(int len1, int len2) {
    if (memo[len1][len2] != -1) {
        return memo[len1][len2];
    }

    if (len1 == 0 || len2 == 0) {
        return memo[len1][len2] = 0;
    } else {
        if (str1[len1 - 1] == str2[len2 - 1]) {
            return memo[len1][len2] = lcs(len1 - 1, len2 - 1) + 1;
        } else {
            return memo[len1][len2] = max(lcs(len1 - 1, len2), lcs(len1, len2 - 1));
        }
    }
}


int main(void) {
    cin >> str1;
    cin >> str2;

    for (int i = 0; i <= MAX_LEN; ++i) {
        for (int j = 0; j <= MAX_LEN; ++j) {
            memo[i][j] = -1;
        }
    }

    printf("%d\n", lcs(str1.length(), str2.length()));

    return EXIT_SUCCESS;
}

