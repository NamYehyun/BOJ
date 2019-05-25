#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string one, two;
    cin >> one >> two;

    vector<int> num;
    for (int i = 0; i < 8; ++i) {
        num.push_back(static_cast<int>(one[i] - '0'));
        num.push_back(static_cast<int>(two[i] - '0'));
    }

    for (int i = 0; i < 14; ++i) {
        vector<int> prev_num = num;
        num.clear();

        int size = prev_num.size();
        for (int j = 1; j < size; ++j) {
            num.push_back((prev_num[j-1] + prev_num[j]) % 10);
        }
    }

    cout << num[0] << num[1] << endl;

    return EXIT_SUCCESS;
}

