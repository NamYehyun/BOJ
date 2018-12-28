#include <iostream>

using namespace std;


const int MAX_NUM = 10000;


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

    int min = -1;
    int sum = 0;
    for (int i = m; i <= n; ++i) {
        if (prime[i]) {
            if (min == -1) {
                min = i;
            }

            sum += i;
        }
    }
    
    if (min == -1) {
        printf("-1\n");
    } else {
        printf("%d\n%d\n", sum, min);
    }
    return EXIT_SUCCESS;
}

