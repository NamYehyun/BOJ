#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = n; i >= 3; --i) {
        cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n"
             << "Take one down and pass it around, "<< i-1 <<" bottles of beer on the wall.\n"
             << "\n";
    }

    if (n >= 2)
        cout << "2 bottles of beer on the wall, 2 bottles of beer.\n"
             << "Take one down and pass it around, 1 bottle of beer on the wall.\n"
             << "\n";

    if (n >= 1)
        cout << "1 bottle of beer on the wall, 1 bottle of beer.\n"
             << "Take one down and pass it around, no more bottles of beer on the wall.\n"
             << "\n";

    if (n != 1)
        cout << "No more bottles of beer on the wall, no more bottles of beer.\n"
             << "Go to the store and buy some more, " << n << " bottles of beer on the wall.\n";
    else
        cout << "No more bottles of beer on the wall, no more bottles of beer.\n"
             << "Go to the store and buy some more, 1 bottle of beer on the wall.\n";

    return EXIT_SUCCESS;
}

