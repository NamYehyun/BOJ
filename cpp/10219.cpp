#include <iostream>

using namespace std;


int main(void) {
    int num_tests;
    scanf("%d", &num_tests);

    while (num_tests--) {
        int h, w;
        scanf("%d%d", &h, &w);

        for (int i = 0; i < h; ++i) {
            string line;
            cin >> line;

            cout << string(line.rbegin(), line.rend()) << endl;
        }
    }
    
    return EXIT_SUCCESS;
}

