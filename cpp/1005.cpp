#include <iostream>

using namespace std;


const int MAX_N = 1000;
const int MAX_K = 100000;
const int MAX_D = 100000;

int n, k;
int cost[MAX_N + 1];
bool order[MAX_N + 1][MAX_N + 1];
int w;

int memo[MAX_N + 1];


void init(void);
int solve(int);


int main(void) {
    int t;
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        init();
        printf("%d\n", solve(w));
    }
    
    return EXIT_SUCCESS;
}


void init(void) {
    for (int i = 1; i <= MAX_N; ++i) {
        cost[i] = -1;
    }

    for (int x = 1; x <= MAX_N; ++x) {
        for (int y = 1; y <= MAX_N; ++y) {
            order[x][y] = false;
        }
    }

    for (int i = 1; i <= MAX_N; ++i) {
        memo[i] = -1;
    }

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", cost + i);
    }

    for (int i = 1; i <= k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        order[x][y] = true;
    }

    scanf("%d", &w);

    return;
}


int solve(int target) {
    if (memo[target] != -1) {
        return memo[target];
    }

    int leading_cost = 0;
    for (int req = 1; req <= n; ++req) {
        if (order[req][target]) {
            int req_cost = solve(req);
            if (leading_cost < req_cost) {
                leading_cost = req_cost;
            }
        }
    }

    return memo[target] = leading_cost + cost[target];
}

