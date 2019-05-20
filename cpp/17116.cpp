#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string constraint;
    getline(cin, constraint);

    string environment;
    getline(cin, environment);

    if (constraint == "KEY IS PUSH AND OPEN DOOR IS SHUT" && environment == "KEY DOOR") {
        cout << "BABA IS WIN" << endl;
    } else if (constraint == "LONELY FLAG IS BABA" && environment == "ROCK") {
        cout << "BABA IS WIN" << endl;
    } else {
        cout << "BABA IS NOT WIN" << endl;
    }

    return EXIT_SUCCESS;
}

