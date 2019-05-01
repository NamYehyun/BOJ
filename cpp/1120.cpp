#include <iostream>

using namespace std;


const int INF = 0x7f7f7f7f;


inline int min(int a, int b) {
    return (a < b) ? a : b;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    int min_cnt = INF;
    for (int base = 0; base < len2 - len1 + 1; ++base) {
        int cnt = 0;
        for (int offset = 0; offset < len1; ++offset) {
            if (str1[offset] != str2[base + offset]) {
                ++cnt;
            }
        }
        
        min_cnt = min(cnt, min_cnt);
    }

    cout << min_cnt << endl;

    return EXIT_SUCCESS;
}

