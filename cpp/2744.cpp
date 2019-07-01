#include <iostream> 

using namespace std;


int main(void) { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string word;
    cin >> word; 

    for (const char& c: word) {
        if ('a' <= c && c <= 'z') {
            cout << static_cast<char>(c - 'a' + 'A');
        } else if ('A' <= c && c <= 'Z') { 
            cout << static_cast<char>(c - 'A' + 'a');
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
} 

