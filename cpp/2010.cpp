#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    long long acc = 1;
    for (int i = 0; i < n; ++i) {
        long long num_socket;
        cin >> num_socket;
        acc += (num_socket-1);
    }

    cout << acc << endl;

    return EXIT_SUCCESS;
}

