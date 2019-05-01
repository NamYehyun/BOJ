#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int girl, boy, intern;
    cin >> girl >> boy >> intern;

    while (intern--) {
        if (girl < 2*boy) {
            --boy;
        } else {
            --girl;
        }
    }

    cout << ((2*boy < girl) ? boy : (girl / 2)) << endl;

    return EXIT_SUCCESS;
}

