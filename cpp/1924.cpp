#include <iostream>

using namespace std;


int main(void) {
    int moon, sun;

    scanf("%d%d", &moon, &sun);

    int count = 0;
    int suns_in_moon[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 1; m < moon; ++m) {
        count += suns_in_moon[m];
    }

    count += sun;

    string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    cout << days[count % 7] << endl;

    return EXIT_SUCCESS;
}

