#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


const int LEFT = false;
const int RIGHT = true;


class Ant {
public:
    int id;
    int dist;
    bool dir;

    Ant(int _dist, bool _dir) {
        dist = _dist;
        dir = _dir;
    }

    bool operator<(const Ant& ant) const {
        return (dist < ant.dist) || (dist == ant.dist && id < ant.id);
    }

};


int main(void) {
    int num_tests;
    scanf("%d", &num_tests);

    while (num_tests--) {
        int n, l, k;
        scanf("%d%d%d", &n, &l, &k);

        vector<int> ids;
        vector<Ant> ants;
        for (int i = 0; i < n; ++i) {
            int pos, id;
            scanf("%d%d", &pos, &id);

            ids.push_back(id);

            if (id < 0) {
                ants.push_back(Ant(pos, LEFT));
            } else {
                ants.push_back(Ant(l - pos, RIGHT));
            }
        }

        int idx = 0;
        vector<Ant>::iterator iter;
        for (iter = ants.begin(); iter != ants.end(); ++iter) {
            if (iter->dir == LEFT) {
                iter->id = ids[idx];
                ++idx;
            }
        }

        for (iter = ants.begin(); iter != ants.end(); ++iter) {
            if (iter->dir == RIGHT) {
                iter->id = ids[idx];
                ++idx;
            }
        }

        sort(ants.begin(), ants.end());

        printf("%d\n", ants[k-1].id);
    }

    return EXIT_SUCCESS;
}

