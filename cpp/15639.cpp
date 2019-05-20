#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string line;
    getline(cin, line);

    if (line == "Give you up" 
          || line == "Let you down" 
          || line == "Run around and desert you" 
          || line == "Make you cry"
          || line == "Say goodbye"
          || line == "Tell a lie and hurt you") {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return EXIT_SUCCESS;
}

