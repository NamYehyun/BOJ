#include <iostream>

using namespace std;


const int MAX_NUM = 1000000;

int main(void) {
    int m, n;

    scanf("%d%d", &m, &n);

    bool prime[MAX_NUM + 1] = {};
    for (int i = 2; i <= MAX_NUM; ++i) {
        prime[i] = true;
    }

    for (int i = 2; i <= MAX_NUM; ++i) {
        if (prime[i]) {
            int mul = 2;
            while (true) {
                int num = mul * i;
                if (MAX_NUM < num) {
                    break;
                }

                prime[num] = false;
                ++mul;
            }
        }
    }

    for (int i = m; i <= n; ++i) {
        if (prime[i]) {
            printf("%d\n", i);
        }
    }

    return EXIT_SUCCESS;
}

