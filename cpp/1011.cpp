#include <iostream>

using namespace std;


long long max_dist(long long n) {
    if (n % 2 == 1) {
        return ((n + 1) / 2) * ((n + 1) / 2);
    } else {
        return (n / 2) * (n / 2 + 1);
    }
}


long long solve(long long dist, long long from, long long to) {
    long long mid = (from + to) / 2;

    if (max_dist(mid-1) < dist && dist <= max_dist(mid)) {
        return mid;
    } else if (dist <= max_dist(mid-1)) {
        return solve(dist, from, mid);
    } else if (max_dist(mid) < dist) {
        return solve(dist, mid+1, to);
    } else {
        // impossible
        return -1;
    }
}


int main(void) {
    int t;
    
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        long long x, y;
        
        scanf("%lld%lld", &x, &y);

        long long dist = y - x;

        printf("%lld\n", solve(dist, 0, 100000));
    }

    return EXIT_SUCCESS;
}

