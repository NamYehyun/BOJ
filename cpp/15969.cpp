#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_stu;
    cin >> num_stu;

    vector<int> score(num_stu);
    for (int i = 0; i < num_stu; ++i) {
        cin >> score[i];
    }

    sort(score.begin(), score.end());

    cout << score[num_stu-1] - score[0] << endl;

    return EXIT_SUCCESS;
}

