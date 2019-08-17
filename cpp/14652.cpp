#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int nrow, ncol, id;
    cin >> nrow >> ncol >> id;

    int row = id / ncol;
    int col = id % ncol;

    cout << row << ' ' << col << endl;

    return EXIT_SUCCESS;
}

