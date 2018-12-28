#include <iostream>

using namespace std;


const int MAX_NUM = 1000;

int main(void) {
    bool prime[MAX_NUM + 1] = {};
    for (int i = 2; i <= MAX_NUM; ++i) {
        prime[i] = true;
    }

    for (int i = 2; i <= MAX_NUM; ++i) {
        if (prime[i]) {
            int mul = 2;
            while(true) {
                int num = mul * i;
                if (MAX_NUM < num) {
                    break;
                }

                prime[num] = false;
                ++mul;
            }
        }
    }
    
    int n;

    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        if (prime[num]) {
            ++count;
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

