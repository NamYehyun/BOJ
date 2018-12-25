#include <iostream>

using namespace std;


int main(void) {
    string num1, num2;

    cin >> num1 >> num2;

    int rev1 = 0;
    int len1 = num1.length();
    for (int i = len1 - 1; i >= 0; --i) {
        rev1 *= 10;
        rev1 += (num1[i] - '0');
    }

    int rev2 = 0;
    int len2 = num2.length();
    for (int i = len2 - 1; i >= 0; --i) {
        rev2 *= 10;
        rev2 += (num2[i] - '0');
    }

    printf("%d\n", (rev2 < rev1) ? rev1 : rev2);

    return EXIT_SUCCESS;
}

