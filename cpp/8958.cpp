#include <iostream>

using namespace std;


int main(void) {
    int n;

    scanf("%d", &n);

    for (int _ = 0; _ < n; ++_) {
        string line;
        cin >> line;

        int acc = 0;
        int score = 0;
        int length = line.length();
        for (int i = 0; i < length; ++i) {
            if (line[i] == 'O') {
                ++acc;
            } else {
                score += (acc * (acc + 1)) / 2;
                acc = 0;
            }
        }

        score += (acc * (acc + 1)) / 2;

        printf("%d\n", score);
    }

    return EXIT_SUCCESS;
}

