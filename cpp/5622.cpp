#include <iostream>

using namespace std;


int alpha_to_num(char a) {
    switch(a) {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return 9;
    default:
        return -1;
    }
}


int main(void) {
    string word;

    cin >> word;

    int time = 0;
    int length = word.length();
    for (int i = 0; i < length; ++i) {
        time += (alpha_to_num(word[i]) + 1);
    }

    printf("%d\n", time);

    return EXIT_SUCCESS;
}

