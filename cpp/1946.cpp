#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Worker {
public:
    int docu_rank, intv_rank;

    Worker(int _docu_rank, int _intv_rank): docu_rank(_docu_rank), intv_rank(_intv_rank) {};

    bool operator<(const Worker& other) const {
        return docu_rank < other.docu_rank;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        int num_worker;
        cin >> num_worker;

        vector<Worker> workers;
        for (int i = 0; i < num_worker; ++i) {
            int docu_rank, intv_rank;
            cin >> docu_rank >> intv_rank;
            workers.push_back(Worker(docu_rank, intv_rank));
        }

        sort(workers.begin(), workers.end());

        int cnt = 1;
        int intv_rank_bound = workers[0].intv_rank;
        for (int i = 1; i < num_worker; ++i) {
            if (workers[i].intv_rank < intv_rank_bound) {
                intv_rank_bound = workers[i].intv_rank;
                ++cnt;
            }
        }

        cout << cnt << endl;
    }

    return EXIT_SUCCESS;
}

