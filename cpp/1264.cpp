#include <iostream>
#include <functional>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    function<bool(char)> is_vowel = [](char c) -> bool {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')
            || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
    };

    while (true) {
        string line;
        getline(cin, line);
        if (line == "#") {
            break;
        }
        
        int cnt = 0;
        for (const char& c: line) {
            if (is_vowel(c)) {
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }

    return EXIT_SUCCESS;
}

