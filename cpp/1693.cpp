#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


int colourize(int node, int banned_colour, int num_colours, vector<vector<int>>& adj_list, vector<bool> visited, vector<vector<int>>& cost) {
    visited[node] = true;

    int min_cost = INF;
    for (int colour = 1; colour <= num_colours; ++colour) {
        if (colour == banned_colour) {
            continue;
        }

        if (cost[node][colour] == INF) {
            int acc = colour;
            for (auto neighbor: adj_list[node]) {
                if (!visited[neighbor]) {
                    acc += colourize(neighbor, colour, num_colours, adj_list, visited, cost);
                }
            }

            cost[node][colour] = acc;
        }

        if (cost[node][colour] < min_cost) {
            min_cost = cost[node][colour];
        }
    }

    return min_cost;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_nodes;
    cin >> num_nodes;

    vector<vector<int>> adj_list(num_nodes+1, vector<int>());
    for (int i = 0; i < num_nodes-1; ++i) {
        int x, y;
        cin >> x >> y;

        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    int num_colours = static_cast<int>(log2(num_nodes)) + 1;
    vector<vector<int>> cost(num_nodes+1, vector<int>(num_colours+1, INF));

    vector<bool> visited(num_nodes+1, false);

    cout << colourize(num_nodes, 0, num_colours, adj_list, visited, cost) << endl;

    return EXIT_SUCCESS;
}

