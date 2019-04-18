#include <iostream>

using namespace std;


inline int max(int x, int y) {
    return (x > y) ? x : y;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int cost, amount, budget;
    cin >> cost >> amount >> budget;

    cout << max(cost * amount - budget, 0) << endl;

    return EXIT_SUCCESS;
}

