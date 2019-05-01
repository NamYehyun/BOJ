#include <iostream>
#include <vector>

using namespace std;


int leaf_count(int curr, vector<vector<int>>& adj_list) {
    if (curr < 0) {
        return 0;
    }

    if (adj_list[curr].empty()) {
        return 1;
    }

    int acc = 0;
    for (int node: adj_list[curr]) {
        acc += leaf_count(node, adj_list);
    }

    return acc;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_node;
    cin >> num_node;

    vector<int> prev(num_node);
    for (int id = 0; id < num_node; ++id) {
        cin >> prev[id];
    }

    int drop;
    cin >> drop;

    int root = -1;
    vector<vector<int>> adj_list(num_node, vector<int>());
    for (int curr = 0; curr < num_node; ++curr) {
        if (curr == drop) {
            continue;
        } else if (prev[curr] == -1) {
            root = curr;
        } else {
            adj_list[prev[curr]].push_back(curr);
        }
    }
    
    cout << leaf_count(root, adj_list) << endl;
    
    return EXIT_SUCCESS;
}

