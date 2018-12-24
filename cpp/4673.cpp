#include <iostream>

using namespace std;


bool is_self_number[10001];


int d(int n) {
    int a = (n / 10000) % 10;
    int b = (n / 1000) % 10;
    int c = (n / 100) % 10;
    int d = (n / 10) % 10;
    int e = n % 10;

    return n + a + b + c + d + e;
}


int main(void) {
    for (int i = 1; i <= 10000; ++i) {
        is_self_number[i] = true;
    }

    for (int i = 1; i <= 10000; ++i) {
        int num = i;
        while(true) {
            num = d(num);
            if (10000 < num) {
                break;
            }
            
            is_self_number[num] = false;
        }
    }

    for (int i = 1; i <= 10000; ++i) {
        if (is_self_number[i])
            printf("%d\n", i);
    }

    return EXIT_SUCCESS;
}

