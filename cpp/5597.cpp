#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> homework(31, false);

    for (int i = 0; i < 28; ++i) {
        int stu;
        cin >> stu;

        homework[stu] = true;
    }

    for (int stu = 1; stu <= 30; ++stu) {
        if (!homework[stu]) {
            cout << stu << endl;
        }
    }

    return EXIT_SUCCESS;
}

