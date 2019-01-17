#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;

const int X_AXIS = 0;
const int Y_AXIS = 1;


class Dot {
public:
    int x, y;

    Dot(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


bool cmp(const Dot& a, const Dot& b) {
    if (a.x == b.x)
        return a.y < b.y;

    return a.x < b.x;
}

bool cmp_x(const Dot& a, const Dot& b) {
    return a.x < b.x;
}

bool cmp_y(const Dot& a, const Dot& b) {
    return a.y < b.y;
}

int dist_square(const Dot& a, const Dot& b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;

    return dx * dx + dy * dy;
}


int solve(vector<Dot>&, int, int);
int lower_bound(vector<Dot>&, int, int, int, int);
int upper_bound(vector<Dot>&, int, int, int, int);


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<Dot> dots;

    cin >> n;
    for(int _ = 0; _ < n; ++_) {
        int x, y;
        cin >> x >> y;

        dots.push_back(Dot(x, y));
    }

    sort(dots.begin(), dots.end(), cmp_x);
    cout << solve(dots, 0, n-1) << endl;

    return EXIT_SUCCESS;
}


int solve(vector<Dot>& dots, int start, int end) {
    if (end <= start) {
        return INF;
    }

    int mid = (start + end) / 2;
    int dist_l = solve(dots, start, mid);
    int dist_r = solve(dots, mid+1, end);

    int dist = (dist_l <= dist_r) ? dist_l : dist_r;

    vector<Dot> mid_dots;

    int lm_dot = lower_bound(dots, start, end+1, dots[mid].x - static_cast<int>(sqrt(dist)), X_AXIS);
    int rm_dot = upper_bound(dots, start, end+1, dots[mid].x + static_cast<int>(sqrt(dist)), X_AXIS);
    for (int i = lm_dot; i < rm_dot; ++i) {
        mid_dots.push_back(dots[i]);
    }

    sort(mid_dots.begin(), mid_dots.end(), cmp_y);

    int size = mid_dots.size();
    for (int i = 0; i < size; ++i) {
        int from = (i < 6) ? 0 : i - 6;
        int to = (size < i + 6) ? size : i + 6;

        for (int j = from; j < to; ++j) {
            if (i == j) {
                continue;
            }

            int d = dist_square(mid_dots[i], mid_dots[j]);
            if (d < dist) {
                dist = d;
            }
        }
    }

    return dist;
}


int lower_bound(vector<Dot>& dots, int start, int end, int key, int axis) {
    int mid = (start + end) / 2;

    while (true) {
        if (end <= start) {
            break;
        }

        if((axis == X_AXIS ? dots[mid].x : dots[mid].y) < key) {
            start = mid + 1;
        } else {
            end = mid;
        }

        mid = (start + end) / 2;
    }

    return mid;
}


int upper_bound(vector<Dot>& dots, int start, int end, int key, int axis) {
    int mid = (start + end) / 2;

    while (true) {
        if (end <= start) {
            break;
        }

        if ((axis == X_AXIS ? dots[mid].x : dots[mid].y) <= key) {
            start = mid + 1;
        } else {
            end = mid;
        }

        mid = (start + end) / 2;
    }

    return mid;
}

