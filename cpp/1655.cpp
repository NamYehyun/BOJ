#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, less<int>> lo_half;     // max heap
    priority_queue<int, vector<int>, greater<int>> hi_half;  // min heap

    for (int i = 0; i < n; ++i) {
        int elt;
        cin >> elt;

        if (lo_half.size() <= hi_half.size()) {
            lo_half.push(elt);
        } else {
            hi_half.push(elt);
        }

        if (!lo_half.empty() && !hi_half.empty() && lo_half.top() > hi_half.top()) {
            int l = lo_half.top();
            int h = hi_half.top();

            lo_half.pop();
            hi_half.pop();

            lo_half.push(h);
            hi_half.push(l);
        }

        cout << lo_half.top() << '\n';
    }

    return EXIT_SUCCESS;
}

