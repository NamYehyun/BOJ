#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> seq {
        65, 17, 4, 4, 64
    };

    int n;
    cin >> n;

    cout << seq[n-1] << endl;

    return EXIT_SUCCESS;
}

