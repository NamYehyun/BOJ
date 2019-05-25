#include <iostream>
#include <set>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    set<int> remainder;
    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;
        remainder.insert(num % 42);
    }

    cout << remainder.size() << endl;

    return EXIT_SUCCESS;
}

