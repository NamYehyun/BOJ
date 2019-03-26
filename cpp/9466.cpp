#include <iostream>
#include <vector>

using namespace std;


const int initial = 0;
const int visited = 1;
const int grouped = 2;
const int failed = 3;


bool group(int stu, vector<int>& next, vector<int>& status) {
    if (status[stu] == initial) {
        status[stu] = visited;
        if (group(next[stu], next, status) && status[stu] == visited) {
            status[stu] = grouped;
            return true;
        } else if (status[stu] == grouped) {
            return false;
        } else {
            status[stu] = failed;
            return false;
        }
    } else if (status[stu] == visited) {
        status[stu] = grouped;
        return true;
    } else {
        return false;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        int n;
        cin >> n;

        vector<int> next(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> next[i];
        }

        vector<int> status(n+1, initial);

        for (int i = 1; i <= n; ++i) {
            if (status[i] == initial) {
                group(i, next, status);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (status[i] == failed) {
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }

    return EXIT_SUCCESS;
}

