#include <iostream>

using namespace std;


const int MAX_CMDS = 10000;

class Stack {
public:
    int rear = 0;
    int stack[MAX_CMDS + 10];

    Stack(void) {}

    void push(int x) {
        stack[rear] = x;
        ++rear;

        return;
    }

    int pop(void) {
        if (rear == 0) {
            return -1;
        } else {
            --rear;
            
            return stack[rear];
        }
    }

    int size(void) {
        return rear;
    }

    bool empty(void) {
        return rear == 0;
    }

    int top(void) {
        if (rear == 0) {
            return -1;
        } else {
            return stack[rear - 1];
        }
    }
};


int main(void) {
    int num_cmds;
    scanf("%d", &num_cmds);

    Stack s;
    for (int _ = 0; _ < num_cmds; ++_) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            scanf("%d", &x);
            s.push(x);
        } else if (cmd == "pop") {
            printf("%d\n", s.pop());
        } else if (cmd == "size") {
            printf("%d\n", s.size());
        } else if (cmd == "empty") {
            printf("%d\n", s.empty());
        } else if (cmd == "top") {
            printf("%d\n", s.top());
        }
    }

    return EXIT_SUCCESS;
}

