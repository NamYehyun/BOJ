#include <iostream>
#include <vector>

using namespace std;


const int W = 2500;


void print(vector<int>& num) {
    int w = W - 1;
    while ((w >= 0) && (num[w] == 0)) {
        --w;
    }

    if (w < 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = w; i >= 0; --i) {
        cout << num[i];
    }
    cout << endl;

    return;
}


void add(vector<int>& a, vector<int>& b, vector<int>& c) {
    for (int w = 0; w < W-1; ++w) {
        int sum = a[w] + b[w] + c[w];
        c[w] = sum % 10;
        c[w+1] = sum / 10;
    }

    return;
}


int main(void) {
    vector<vector<int>> fibo(10000+1, vector<int>(W, 0));
    fibo[1][0] = 1;

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        add(fibo[i-2], fibo[i-1], fibo[i]);
    }

    print(fibo[n]);

    return EXIT_SUCCESS;
}

