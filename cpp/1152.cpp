#include <iostream>
#include <string>

using namespace std;


int main(void) {
    string line;

    getline(cin, line);

    int count = 0;
    int length = line.length();
    bool blank = true;
    for (int i = 0; i < length; ++i) {
        if (blank && (line[i] != ' ')) {
            ++count;
        } 

        blank = (line[i] == ' ');
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}

