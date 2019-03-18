#include <iostream>
#include <vector>

using namespace std;


void select(int n, vector<int>& number, int size, vector<int>& selected, int last_index) {
    if (n == 0) {
        for (int s: selected) {
            cout << s << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = last_index+1; i < size; ++i) {
        selected.push_back(number[i]);
        select(n-1, number, size, selected, i);
        selected.pop_back();
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        int k;
        cin >> k;
        if (!k) {
            break;
        }

        vector<int> num(k);
        for (int i = 0; i < k; ++i) {
            cin >> num[i];
        }
        
        vector<int> selected;
        select(6, num, k, selected, -1);
        cout << '\n';
    }
    return EXIT_SUCCESS;
}

