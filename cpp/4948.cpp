#include <iostream>

using namespace std;


const int MAX_NUM = 123456 * 2;


int main(void) {
    bool prime[MAX_NUM + 1];

    prime[0] = false;
    prime[1] = false;
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

    while (true) {
        int n;
        
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        int count = 0;
        const int lower = n + 1;
        const int upper = 2 * n;
        for (int i = lower; i <= upper; ++i) {
            if (prime[i]) {
                ++count;
            }
        }

        printf("%d\n", count);
    }

    return EXIT_SUCCESS;
}

