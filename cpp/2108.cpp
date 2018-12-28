#include <iostream>

using namespace std;


const int MAX_ELT = 4001;


int num_to_idx(int num) {
    return num + MAX_ELT;
}


int idx_to_num(int idx) {
    return idx - MAX_ELT;
}


int main(void) {
    int n;
    int count[2 * MAX_ELT + 1] = {};

    scanf("%d", &n);

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        int elt;
        scanf("%d", &elt);

        count[num_to_idx(elt)] += 1;
        sum += elt;
    }

    printf("%.0f\n", sum / n);

    int mid = -1;
    int acc = 0;
    for (int i = 0; i < 2 * MAX_ELT + 1; ++i) {
        acc += count[i];
        if (n < 2 * acc) {
            mid = idx_to_num(i);
            break;
        }
    }

    printf("%d\n", mid);

    int max_count = 0;
    for (int i = 0; i < 2 * MAX_ELT + 1; ++i) {
        if (max_count < count[i]) {
            max_count = count[i];
        }
    }

    int tmp = 2;
    int mode = -1;
    for (int i = 0; i < 2 * MAX_ELT + 1; ++i) {
        if (count[i] == max_count && tmp > 0) {
            mode = idx_to_num(i);
            --tmp;
        }
    }

    printf("%d\n", mode);

    int min = -1;
    int max = -1;
    for (int i = 0; i < 2 * MAX_ELT + 1; ++i) {
        if (count[i] != 0) {
            min = idx_to_num(i);
            break;
        }
    }

    for (int i = 2 * MAX_ELT - 1; i >= 0; --i) {
        if (count[i] != 0) {
            max = idx_to_num(i);
            break;
        }
    }

    printf("%d\n", max - min);
    
    return EXIT_SUCCESS;
}

