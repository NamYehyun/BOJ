#include <iostream>
#include <functional>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    function<int(char)> value = [](char c) -> int {
        if ('A' <= c && c <= 'Z') {
            return static_cast<int>(c - 'A' + 1);
        }

        return 0;
    };

    while (true) {
        string line;
        getline(cin, line);

        if (line == "#") {
            break;
        }

        int quicksum = 0;
        int length = line.length();
        for (int i = 0; i < length; ++i) {
            quicksum += (value(line[i]) * (i+1));
        }

        cout << quicksum << '\n';
    }

    return EXIT_SUCCESS;
}

