#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string input;
    cin >> input;

    int length = input.length();
    for (int i = 0; i < length-1; ++i) {
        if ((input[i] == '(') && (input[i+1] == ')')) {
            input[i] = input[i+1] = '*';
        }
    }

    int line_count = 0;
    int part_count = 0;
    for (int i = 0; i < length; ++i) {
        if (input[i] == '(') {
            ++line_count;
        } else if (input[i] == ')') {
            --line_count;
            ++part_count;
        } else {
            part_count += line_count;
            ++i;
        }
    }

    cout << part_count << endl;
    
    return EXIT_SUCCESS;
}

