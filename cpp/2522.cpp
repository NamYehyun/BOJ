#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    for (int num_star = 1; num_star <= n; ++num_star) {
        int num_space = n - num_star;
        for (int space = 0; space < num_space; ++space) cout << ' ';
        for (int star = 0; star < num_star; ++star) cout << '*';
        cout << endl;
    }

    for (int num_space = 1; num_space <= n-1; ++num_space) {
        int num_star = n - num_space;
        for (int space = 0; space < num_space; ++space) cout << ' ';
        for (int star = 0; star < num_star; ++star) cout << '*';
        cout << endl;
    }

    return EXIT_SUCCESS;
}

