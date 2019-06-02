#include <iostream>
#include <stack>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_word;
    cin >> num_word;

    int cnt = 0;
    while (num_word--) {
        stack<char> stack;

        string word;
        cin >> word;

        int length = word.length();
        for (int i = 0; i < length; ++i) {
            if (stack.empty() || stack.top() != word[i]) {
                stack.push(word[i]);
            } else {
                stack.pop();
            }
        }

        if (stack.empty()) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return EXIT_SUCCESS;
}

