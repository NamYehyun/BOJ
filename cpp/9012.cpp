#include <iostream>

using namespace std;


int main(void) {
    int t;
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        string line;
        cin >> line;

        bool valid = true;
        int top = 0;
        int length = line.length();
        for (int i = 0; i < length; ++i) {
            char p = line[i];
            if (p == '(') {
                ++top;
            } else {
                --top;
            }

            if (top < 0) {
                valid = false;
                break;
            }
        }

        if (valid && (top == 0)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return EXIT_SUCCESS;
}

