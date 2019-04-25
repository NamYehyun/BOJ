#include <iostream>
#include <map>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    map<string, int> value = {
        {"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9},
    };

    string first, second, third;
    cin >> first >> second >> third;

    if (first != "black") {
        cout << value[first];
    }

    cout << value[second];

    if (!(first == "black" && second == "black")) {
        for (int i = 0; i < value[third]; ++i) {
            cout << 0;
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

