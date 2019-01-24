#include <iostream>
#include <vector>

using namespace std;


const int SUCCESS = 0;
const int FAILURE = 1;
const int UNCERTAIN = 2;


int topo_sort(int num_teams, vector<vector<bool>>& adj_matrix, vector<int>& result) {
    vector<int> indegree(num_teams+1, 0);
    for (int from = 1; from <= num_teams; ++from) {
        for (int to = 1; to <= num_teams; ++to) {
            if (adj_matrix[from][to]) {
                ++indegree[to];
            }
        }
    }

    int rank = 0;
    while (true) {
        if (rank == num_teams) {
            return SUCCESS;
        }

        vector<int> queue;
        for (int team = 1; team <= num_teams; ++team) {
            if (indegree[team] == 0) {
                queue.push_back(team);
            }
        }

        if (queue.size() == 0) {
            return FAILURE;
        } else if (queue.size() >= 2) {
            return UNCERTAIN;
        } else {
            int root = queue[0];
            for (int team = 1; team <= num_teams; ++team) {
                if (adj_matrix[root][team]) {
                    --indegree[team];
                }
            }

            indegree[root] = -1;
            result[rank] = root;
            ++rank;
        }
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int num_teams;
        cin >> num_teams;

        vector<int> rank(num_teams);
        for (int i = 0; i < num_teams; ++i) {
            cin >> rank[i];
        }

        vector<vector<bool>> adj_matrix(num_teams+1, vector<bool>(num_teams+1, false));
        for (int i = 0; i < num_teams; ++i) {
            for (int j = i+1; j < num_teams; ++j) {
                adj_matrix[rank[i]][rank[j]] = true;
            }
        }

        int num_pairs;
        cin >> num_pairs;
        for (int i = 0; i < num_pairs; ++i) {
            int x, y;
            cin >> x >> y;

            adj_matrix[x][y] = !adj_matrix[x][y];
            adj_matrix[y][x] = !adj_matrix[y][x];
        }

        vector<int> result(num_teams);
        int status = topo_sort(num_teams, adj_matrix, result);
        if (status == SUCCESS) {
            for (int& team: result) {
                cout << team << ' ';
            }
            cout << '\n';
        } else if (status == FAILURE) {
            cout << "IMPOSSIBLE\n";
        } else if (status == UNCERTAIN) {
            cout << "?\n";
        }
    }

    return EXIT_SUCCESS;
}

