#include <iostream>
#include <set>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int size_A, size_B;
    cin >> size_A >> size_B;

    set<int> diff;
    for (int i = 0; i < size_A; ++i) {
        int elt;
        cin >> elt;
        diff.insert(elt);
    }

    for (int i = 0; i < size_B; ++i) {
        int elt;
        cin >> elt;
        if (diff.find(elt) != diff.end()) {
            diff.erase(elt);
        } else {
            diff.insert(elt);
        }
    }

    cout << diff.size() << endl;

    return EXIT_SUCCESS;
}

