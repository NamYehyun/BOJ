#include <iostream>

using namespace std;


const int MAX_N = 100000;


class Stack {
public:
    int top;
    int stack[MAX_N];

    Stack(void) {
        top = 0;
    }

    void push(int elt) {
        stack[top] = elt;
        ++top;

        return;
    }

    int pop(void) {
        if (top == 0) {
            return -1;
        } else {
            --top;
            return stack[top];
        }
    }

    int peek(void) {
        if (top == 0) {
            return -1;
        } else {
            return stack[top - 1];
        }
    }

    void print(void) {
        printf("stack: [ ");
        for (int i = 0; i < top; ++i) {
            printf("%d ", stack[i]);
        }
        printf("]\n");

        return;
    }
};

int main(void) {
    int n;
    int target[MAX_N];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", target+i);
    }

    Stack s;
    int next = 0;
    string answer = "";
    for (int i = 1; i <= n; ++i) {
        s.push(i);
        answer += '+';

        while (true) {
            if (s.peek() == target[next]) {
                s.pop();
                ++next;
                
                answer += '-';
            } else {
                break;
            }
        }
    }

    if (s.peek() == -1) {
        int length = answer.length();
        for (int i = 0; i < length; ++i) {
            printf("%c\n", answer[i]);
        }
    } else {
        printf("NO\n");
    }

    return EXIT_SUCCESS;
}

