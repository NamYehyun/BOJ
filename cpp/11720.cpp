#include <iostream>

using namespace std;


int main(void) {
    int n;
    string line;
    
    cin >> n >> line;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (line[i] - '0');
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}

