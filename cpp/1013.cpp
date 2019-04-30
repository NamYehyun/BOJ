#include <iostream>
#include <regex>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const regex signal("(100+1+|01)+");

    int num_test;
    cin >> num_test;

    while (num_test--) {
        string word;
        cin >> word;
        cout << (regex_match(word, signal) ? "YES" : "NO") << '\n';
    }

    return EXIT_SUCCESS;
}

