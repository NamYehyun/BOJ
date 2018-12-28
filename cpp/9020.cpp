#include <iostream>

using namespace std;


const int MAX_NUM = 10000;

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

    int t;
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int n;
        scanf("%d", &n);
        
        int p1, p2;
        const int bound = n / 2;
        for (int i = 2; i <= bound; ++i) {
            if (prime[i] && prime[n - i]) {
                p1 = i;
                p2 = n - i;
            }
        }

        printf("%d %d\n", p1, p2);
    }
    
    return EXIT_SUCCESS;
}

