#include <iostream>
#include <vector>

using namespace std;


inline int max(int a, int b) {
    return (a > b) ? a : b;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        int hp, mp, att, def;
        cin >> hp >> mp >> att >> def;

        int dhp, dmp, datt, ddef;
        cin >> dhp >> dmp >> datt >> ddef;

        hp += dhp;
        mp += dmp;
        att += datt;
        def += ddef;

        hp = max(hp, 1);
        mp = max(mp, 1);
        att = max(att, 0);

        cout << 1*hp + 5*mp + 2*att + 2*def << '\n';
    }
    
    return EXIT_SUCCESS;
}

