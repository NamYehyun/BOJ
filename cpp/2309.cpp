#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    vector<int> height(9);
    for (int i = 0; i < 9; ++i) {
        cin >> height[i];
    }

    sort(height.begin(), height.end());

    int sum = 0;
    for (auto h: height) {
        sum += h;
    }

    int diff = sum - 100;
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (height[i] + height[j] == diff) {
                for (int k = 0; k < 9; ++k) {
                    if (k == i || k == j) {
                        continue;
                    }
                    cout << height[k] << endl;
                }

                return EXIT_SUCCESS;
            }
        }
    }

    return EXIT_SUCCESS;
}

