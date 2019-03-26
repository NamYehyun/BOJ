#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Interval {
public:
    int start, finish;
    
    Interval(int _start, int _finish): start(_start), finish(_finish) {}

    bool operator<(const Interval& other) const {
        if (finish == other.finish) {
            return start < other.start;
        }

        return finish < other.finish;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<Interval> schedule;
    for (int i = 0; i < n; ++i) {
        int start, finish;
        cin >> start >> finish;
        schedule.emplace_back(start, finish);
    }

    sort(schedule.begin(), schedule.end());

    int cnt = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        if (curr <= schedule[i].start) {
            curr = schedule[i].finish;
            ++cnt;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

