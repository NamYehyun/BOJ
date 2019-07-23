#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;

    char c;
    while (cin.get(c) && c != '\n');

    while (num_test--) {
        string line;
        getline(cin, line);

        stringstream ss(line);

        string word;
        vector<string> words;
        while (ss >> word) {
            words.emplace_back(word);
        }

        while (true) {
            string line;
            getline(cin, line);

            if (line == "what does the fox say?") {
                break;
            }

            stringstream ss(line);
            
            string animal, goes, sound;
            ss >> animal >> goes >> sound;

            for (auto& word: words) {
                if (word == sound) {
                    word = "@";
                }
            }
        }

        for (const auto& word: words) {
            if (word != "@") {
                cout << word << ' ';
            }
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

