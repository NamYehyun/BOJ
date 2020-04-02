#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


inline int abs(int x) {
    return (x > 0) ? x : -x;
}

inline int min(int x, int y) {
    return (x < y) ? x : y;
}


int min_diff(int i, int n, vector<vector<int>>& synergy, int team_x_syn, vector<int>& team_x, int team_y_syn, vector<int>& team_y) {
    if (i == n) {
        return abs(team_x_syn - team_y_syn);
    }

    int syn = 0, case_x = INF, case_y = INF;

    if (static_cast<int>(team_x.size()) < n/2) {
        syn = 0;
        for (int j: team_x) {
            syn += (synergy[i][j] + synergy[j][i]);
        }
        
        team_x.push_back(i);
        case_x = min_diff(i+1, n, synergy, team_x_syn + syn, team_x, team_y_syn, team_y);
        team_x.pop_back();
    }

    if (static_cast<int>(team_y.size()) < n/2) {
        syn = 0;
        for (int j: team_y) {
            syn += (synergy[i][j] + synergy[j][i]);
        }

        team_y.push_back(i);
        case_y = min_diff(i+1, n, synergy, team_x_syn, team_x, team_y_syn + syn, team_y);
        team_y.pop_back();
    }

    return min(case_x, case_y);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> synergy(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> synergy[i][j];
        }
    }

    vector<int> team_x;
    vector<int> team_y;
    cout << min_diff(0, n, synergy, 0, team_x, 0, team_y) << endl;

    return EXIT_SUCCESS;
}

