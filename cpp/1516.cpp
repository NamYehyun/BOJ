#include <iostream>
#include <vector>

using namespace std;


int total_cost(int node, vector<int>& cost, vector<vector<int>>& prereq, vector<int>& memo) {
    if (memo[node] != -1) {
        return memo[node];
    }

    int max_req_cost = 0;
    for (int req: prereq[node]) {
        int req_cost = total_cost(req, cost, prereq, memo);
        if (max_req_cost < req_cost) {
            max_req_cost = req_cost;
        }
    }

    return memo[node] = max_req_cost + cost[node];
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes;
    cin >> num_nodes;

    vector<vector<int>> prerequisite(num_nodes+1, vector<int>());
    vector<int> cost(num_nodes+1, 0);
    for (int node = 1; node <= num_nodes; ++node) {
        cin >> cost[node];

        while (true) {
            int req;
            cin >> req;

            if (req == -1) {
                break;
            }

            prerequisite[node].push_back(req);
        }
    }

    vector<int> memo(num_nodes+1, -1);
    for (int node = 1; node <= num_nodes; ++node) {
        cout << total_cost(node, cost, prerequisite, memo) << '\n';
    }

    return EXIT_SUCCESS;
}

