#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


const int MAX_N = 100;


long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


int main(void) {
    int n;
    long long num[MAX_N];
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", num + i);
    }

    sort(num, num + n);

    long long m = num[1] - num[0];
    for (int i = 1; i < n - 1; ++i) {
        m = gcd(m, num[i + 1] - num[i]);
    }

    vector<long long> ans;
    for (long long i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            ans.push_back(i);
        }
    }

    int size = ans.size();
    for (int i = 0; i < size; ++i) {
        long long x = ans[i];
        if (m != x * x) {
            ans.push_back(m / x);
        }
    }

    sort(ans.begin(), ans.end());

    size = ans.size();
    for (int i = 1; i < size; ++i) {
        printf("%lld ", ans[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}

