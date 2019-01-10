#include <iostream>

using namespace std;


int curr = 100;
int target;
int m;
bool is_broken[10];


int abs(int x) {
    return (x > 0) ? x : -x;
}


int min(int a, int b) {
    return (a < b) ? a : b;
}


bool can_jump(int to) {
    string str = to_string(to);
    
    int length = str.length();
    for (int i = 0; i < length; ++i) {
        if (is_broken[str[i] - '0']) {
            return false;
        }
    }

    return true;
}


int main(void) {
    scanf("%d", &target);

    for (int i = 0; i <= 9; ++i) {
        is_broken[i] = false;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int button;
        scanf("%d", &button);
        is_broken[button] = true;
    }

    int ans = abs(target - curr);
    for (int tmp = 0; tmp < 1000000; ++tmp) {
        if (can_jump(tmp)) {
            ans = min(ans, to_string(tmp).length() + abs(target - tmp));
        }
    }


    printf("%d\n", ans);

    return EXIT_SUCCESS;
}

