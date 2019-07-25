#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7fffffff;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int len_a, len_b;
    cin >> len_a >> len_b;

    vector<int> a(len_a+1, INF);
    for (int i = 0; i < len_a; ++i) {
        cin >> a[i];
    }

    vector<int> b(len_b+1, INF);
    for (int i = 0; i < len_b; ++i) {
        cin >> b[i];
    }

    int ptr_a = 0;
    int ptr_b = 0;
    for (int i = 0; i < len_a + len_b; ++i) {
        if (a[ptr_a] < b[ptr_b]) {
            cout << a[ptr_a] << ' ';
            ++ptr_a;
        } else {
            cout << b[ptr_b] << ' ';
            ++ptr_b;
        }
    }
    cout << endl;
    
    return EXIT_SUCCESS;
}

