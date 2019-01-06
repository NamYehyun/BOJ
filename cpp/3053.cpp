#include <iostream>
#include <cmath>

using namespace std;


const double pi = acos(-1.0);


int main(void) {
    double r;
    scanf("%lf", &r);

    printf("%f\n", r * r * pi);
    printf("%f\n", r * r * 2);

    return EXIT_SUCCESS;
}

