#include <iostream>
#include <vector>

using namespace std;


class Nation {
public:
    int id;
    int gold, silver, bronze;

    Nation(int _id, int _gold, int _silver, int _bronze) {
        id = _id;
        gold = _gold;
        silver = _silver;
        bronze = _bronze;
    }

    bool operator<(const Nation& n) const {
        if (gold == n.gold) {
            if (silver == n.silver) {
                return bronze < n.bronze;
            }

            return silver < n.silver;
        }

        return gold < n.gold;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_nations, k;
    cin >> num_nations >> k;

    Nation* target = nullptr;
    vector<Nation*> nations;
    for (int i = 0; i < num_nations; ++i) {
        int id, g, s, b;
        cin >> id >> g >> s >> b;

        Nation* nation = new Nation(id, g, s, b);
        nations.push_back(nation);

        if (id == k) {
            target = nation;
        }
    }

    int rank = 1;
    for (Nation* nation: nations) {
        if ((*target) < (*nation)) {
            ++rank;
        }
    }

    cout << rank << endl;

    return EXIT_SUCCESS;
}

