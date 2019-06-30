#include <iostream> 

using namespace std;
 

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    auto value_of = [](char c) -> int {
        if ('0' <= c && c <= '9') {
            return static_cast<int>(c - '0'); 
        } else if ('a' <= c && c <= 'f') {
            return static_cast<int>(c - 'a' + 10);
        }
        return 0; 
    };

    string num; 
    cin >> num;

    int ans = 0;
    int length = num.length(); 
    if (num[0] == '0') {
        if (length > 1 && num[1] == 'x') {
            for (int i = 2; i < length; ++i) { 
                ans *= 16;
                ans += value_of(num[i]);
            } 
        } else {
            for (int i = 1; i < length; ++i) {
                ans *= 8;
                ans += value_of(num[i]); 
            }
        }
    } else {
        for (int i = 0; i < length; ++i) {
            ans *= 10;
            ans += value_of(num[i]); 
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

