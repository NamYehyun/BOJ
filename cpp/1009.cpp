#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> memo{
        {10}, 
        {1}, 
        {2, 4, 8, 6}, 
        {3, 9, 7, 1}, 
        {4, 6}, 
        {5}, 
        {6},
        {7, 9, 3, 1}, 
        {8, 4, 2, 6},
        {9, 1},
    };

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        
        a = a % 10;
        cout << memo[a][(b - 1) % memo[a].size()] << '\n';
    }

    return EXIT_SUCCESS;
}

