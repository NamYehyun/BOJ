#include <iostream>

using namespace std;


const int MAX_N = 1000;


void merge(int* lower, int* mid, int* upper) {
    int count = upper - lower;
    int* p1 = lower;
    int* p2 = mid;
    int* tmp = new int[count];
    for (int i = 0; i < count; ++i) {
        if (p1 == mid) {
            tmp[i] = *p2;
            ++p2;
        } else if (p2 == upper) {
            tmp[i] = *p1;
            ++p1;
        } else {
            if (*p1 < *p2) {
                tmp[i] = *p1;
                ++p1;
            } else {
                tmp[i] = *p2;
                ++p2;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        lower[i] = tmp[i];
    }

    delete[] tmp;

    return;
}


void merge_sort(int* lower, int* upper) {
    int count = upper - lower;
    if (count == 1) {
        return;
    } else {
        int* mid = lower + (count / 2);
        merge_sort(lower, mid);
        merge_sort(mid, upper);
        merge(lower, mid, upper);
       
        return;
    }
}


int main(void) {
    int n;
    int num[MAX_N];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }

    merge_sort(num, num + n);

    for (int i = 0; i < n; ++i) {
        printf("%d\n", num[i]);
    }

    return EXIT_SUCCESS;
}

