#include <iostream>

using namespace std;


const long long DIV = 1000000007;


class Matrix {
public:
    long long matrix[2][2];

    Matrix(long long a, long long b, long long c, long long d) {
        matrix[0][0] = a; matrix[0][1] = b;
        matrix[1][0] = c; matrix[1][1] = d;
    }

    Matrix operator*(const Matrix& other) {
        long long a = (matrix[0][0] * other.matrix[0][0] + matrix[0][1] * other.matrix[1][0]) % DIV;
        long long b = (matrix[0][0] * other.matrix[0][1] + matrix[0][1] * other.matrix[1][1]) % DIV;
        long long c = (matrix[1][0] * other.matrix[0][0] + matrix[1][1] * other.matrix[1][0]) % DIV;
        long long d = (matrix[1][0] * other.matrix[0][1] + matrix[1][1] * other.matrix[1][1]) % DIV;

        return Matrix(a, b, c, d);
    }

    Matrix pow(long long n) {
        if (n == 0) {
            return Matrix(1, 0, 0, 1);
        } else {
            if (n % 2 == 0) {
                Matrix sqrt = pow(n/2);
                return sqrt * sqrt;
            } else {
                Matrix sqrt = pow(n/2);
                return sqrt * sqrt * (*this);
            }
        }
    }

    void print(void) {
        printf("| %6lld %6lld |\n", matrix[0][0], matrix[0][1]);
        printf("| %6lld %6lld |\n", matrix[1][0], matrix[1][1]);
    }
};


long long fibo(long long n) {
    Matrix seed(1, 1, 1, 0);
    return seed.pow(n).matrix[0][1];
}


long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}


int main(void) {
    long long n, m;
    scanf("%lld%lld", &n, &m);

    printf("%lld\n", fibo(gcd(n, m)));

    return EXIT_SUCCESS;
}

