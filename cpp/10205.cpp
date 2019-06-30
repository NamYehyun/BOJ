#include <iostream> 

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    for (int test = 1; test <= num_test; ++test) { 
        cout << "Data Set " << test << ":\n";
        int head;
        cin >> head;

        string ops;
        cin >> ops;

        for (const char& op: ops) {
            head += (op == 'c' ? 1 : -1);
        } 

        cout << head << '\n';

        if (test != num_test) { 
            cout << '\n';
        }
    } 

    return EXIT_SUCCESS;
}

