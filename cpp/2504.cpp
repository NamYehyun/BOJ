#include <iostream>

using namespace std;


const int MAX_LEN = 30;
const char EMPTY = 'x';


class Stack {
public:
    int top;
    char stack[MAX_LEN];

    Stack(void) {
        top = 0;
    }

    void push(int elt) {
        stack[top] = elt;
        ++top;

        return;
    }

    char pop(void) {
        if (top == 0) {
            return EMPTY;
        } else {
            --top;

            return stack[top];
        }
    }

    int peek(void) {
        if (top == 0) {
            return EMPTY;
        } else {
            return stack[top - 1];
        }
    }

    bool empty(void) {
        return top == 0;
    }
};


bool valid(string line) {
    Stack s;
    bool match = true;
    int length = line.length();
    for (int i = 0; i < length; ++i) {
        char p = line[i];
        if ((p == '(') || (p == '[')) {
            s.push(p);
        } else if (p == ')') {
            if (s.peek() == '(') {
                s.pop();
            } else {
                match = false;
                break;
            }
        } else if (p == ']') {
            if (s.peek() == '[') {
                s.pop();
            } else {
                match = false;
                break;
            }
        }
    }

    return match && s.empty();
}

int score(string line) {
    int length = line.length();
    if (length == 0) {
        return 1;
    }
    
    int acc = 0;
    int pos = 0;
    int count = 0;
    for (int i = 0; i < length; ++i) {
        char p = line[i];
        if ((p == '(') || (p == '[')) {
            ++count;
        } else if ((p == ')') || (p == ']')) {
            --count;
        }

        if (count == 0) {
            int len = i + 1 - pos;
            if (len == length) {
                if (line[0] == '(') {
                    return 2 * score(line.substr(1, length-2));
                } else if (line[0] == '[') {
                    return 3 * score(line.substr(1, length-2));
                }
            } else {
                acc += score(line.substr(pos, len));
                pos = i + 1;
            }
        }
    }

    return acc;
}

int main(void) {
    string line;
    cin >> line;

    if (valid(line)) {
        printf("%d\n", score(line));
    } else {
        printf("0\n");
    }

    return EXIT_SUCCESS;
}

