#include <iostream>
#include <vector>

using namespace std;


int digital_root(int num) {
    int acc = 0;
    while (num) {
        acc += (num % 10);
        num /= 10;
    }

    return (acc < 10 ? acc : digital_root(acc));
}


int digital_root(string num) {
    int acc = 0;
    int length = num.length();
    for (int i = 0; i < length; ++i) {
        acc += static_cast<int>(num[i] - '0');
    }

    return (acc < 10 ? acc : digital_root(acc));
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        string num;
        cin >> num;

        if (num == "0") {
            break;
        }

        cout << digital_root(num) << endl;
    }

    return EXIT_SUCCESS;
}

