#include <iostream>

using namespace std;


const int MAX_K = 500;
const int MAX_INT = 0x7fffffff;

int t;
int k;
int pages[MAX_K];
int sum_pages[MAX_K][MAX_K];
int cost[MAX_K][MAX_K];


void init(void) {
    for (int i = 0; i < MAX_K; ++i) {
        pages[i] = -1;
    }

    for (int i = 0; i < MAX_K; ++i) {
        for (int j = 0; j < MAX_K; ++j) {
            sum_pages[i][j] = -1;
        }
    }

    for (int i = 0; i < MAX_K; ++i) {
        for (int j = 0; j < MAX_K; ++j) {
            cost[i][j] = -1;
        }
    }

    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        scanf("%d", pages + i);
    }

    return;
}


int add_pages(int start, int end) {
    if (sum_pages[start][end] != -1) {
        return sum_pages[start][end];
    }

    if (start == end) {
        return sum_pages[start][end] = pages[start];
    } else {
        for (int p = start; p < end; ++p) {
            add_pages(start, p);
            add_pages(p + 1, end);
        }

        return sum_pages[start][end] = add_pages(start, end - 1) + add_pages(end, end);
    }
}


int solve(int start, int end) {
    if (cost[start][end] != -1) {
        return cost[start][end];
    }

    if (start == end) {
        return cost[start][end] = 0;
    } else {
        int min_cost = MAX_INT;
        for (int p = start; p < end; ++p) {
            int tmp = solve(start, p) + solve(p + 1, end);
            if (tmp < min_cost) {
                min_cost = tmp;
            }
        }

        return cost[start][end] = min_cost + add_pages(start, end);
    }
}


int main(void) {
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        init();
        printf("%d\n", solve(0, k - 1));
    }

    return EXIT_SUCCESS;
}

