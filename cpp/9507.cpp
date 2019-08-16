#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<unsigned long long> koong {
        1, 1, 2, 4
    };

    for (int i = 4; i <= 67; ++i) {
        koong.push_back(koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4]);
    }

    int num_query;
    cin >> num_query;
    while (num_query--) {
        int n;
        cin >> n;
        cout << koong[n] << '\n';
    }

    return EXIT_SUCCESS;
}

