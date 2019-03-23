#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> stu(n);
    for (int i = 0; i < n; ++i) {
        cin >> stu[i];
    }

    int x, y;
    cin >> x >> y;

    unsigned long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        stu[i] -= x;
        ++cnt;

        if (stu[i] > 0) {
            cnt += static_cast<unsigned long long>((stu[i] / y) + (stu[i] % y != 0));
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

