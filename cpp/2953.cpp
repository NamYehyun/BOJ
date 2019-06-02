#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> net_score;
    net_score.push_back(0);

    for (int i = 0; i < 5; ++i) {
        int acc = 0;
        for (int j = 0; j < 4; ++j) {
            int score;
            cin >> score;
            acc += score;
        }

        net_score.push_back(acc);
    }

    int max = 0;
    int max_id = 0;
    for (int i = 1; i <= 5; ++i) {
        if (max < net_score[i]) {
            max = net_score[i];
            max_id = i;
        }
    }

    cout << max_id << ' ' << max << endl;

    return EXIT_SUCCESS;
}

