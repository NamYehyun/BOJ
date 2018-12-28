#include <iostream>
#include <map>

using namespace std;


const int MAX_N = 20000;


bool comp(string str1, string str2) {
    if (str1.length() < str2.length()) {
        return true;
    }

    if (str2.length() < str1.length()) {
        return false;
    }

    return str1 < str2; 
}


void merge(string* lower, string* mid, string* upper) {
    int count = upper - lower;

    string* p1 = lower;
    string* p2 = mid;
    string* tmp = new string[count];
    for (int i = 0; i < count; ++i) {
        if (p1 == mid) {
            tmp[i] = *p2;
            ++p2;
        } else if (p2 == upper) {
            tmp[i] = *p1;
            ++p1;
        } else {
            if (comp(*p1, *p2)) {
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


void merge_sort(string* lower, string* upper) {
    int count = upper - lower;
    if (count == 1) {
        return;
    } else {
        string* mid = lower + (count / 2);
        
        merge_sort(lower, mid);
        merge_sort(mid, upper);

        merge(lower, mid, upper);

        return;
    }
}


int main(void) {
    int n;
    string words[MAX_N];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    merge_sort(words, words + n);

    map<string, bool> exists;
    for (int i = 0; i < n; ++i) {
        exists[words[i]] = false;
    }

    for (int i = 0; i < n; ++i) {
        if (!exists[words[i]]) {
            exists[words[i]] = true;
            cout << words[i] << endl;
        }
    }

    return EXIT_SUCCESS;
}

