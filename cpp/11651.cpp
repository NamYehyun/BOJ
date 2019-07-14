#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Dot {
public:
    int x, y;

    Dot(int _x, int _y): x(_x), y(_y) {}

    bool operator<(const Dot& other) const {
        if (y == other.y) {
            return x < other.x;
        }

        return y < other.y;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Dot> dots;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        dots.emplace_back(x, y);
    }

    sort(dots.begin(), dots.end());

    for (const Dot& dot: dots) {
        cout << dot.x << ' ' << dot.y << '\n';
    }
    
    return EXIT_SUCCESS;
}

