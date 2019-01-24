#include <iostream>
#include <vector>

using namespace std;


void infect(int target, vector<vector<int>>& adj_list, vector<bool>& infected) {
    infected[target] = true;

    for (int neighbor: adj_list[target]) {
        if (!infected[neighbor]) {
            infect(neighbor, adj_list, infected);
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_devices, num_edges;
    cin >> num_devices >> num_edges;

    vector<vector<int>> adj_list(num_devices+1, vector<int>());
    for (int i = 0; i < num_edges; ++i) {
        int x, y;
        cin >> x >> y;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    vector<bool> infected(num_devices+1, false);
    infect(1, adj_list, infected);

    int cnt = 0;
    for (int device = 2; device <= num_devices; ++device) {
        if (infected[device]) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

