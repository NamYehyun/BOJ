#include <iostream> 

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 

    int n;
    cin >> n;

    string prev, curr;
    cin >> prev >> curr; 

    bool success = true;
    if (n % 2 == 0) {
        int length = prev.length();
        for (int i = 0; i < length; ++i) { 
            if (prev[i] != curr[i]) {
                success = false;
            }
        }
    } else { 
        int length = prev.length();
        for (int i = 0; i < length; ++i) {
            if (prev[i] == curr[i]) {
                success = false;
            } 
        }
    }

    cout << (success ? "Deletion succeeded" : "Deletion failed") << endl;

    return EXIT_SUCCESS;
}

