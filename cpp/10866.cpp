#include <iostream>

using namespace std;


const int MAX_ELT = 10000;
const int ERROR = -1;

class Deque {
public:
    int front;
    int back;
    int deque[2 * MAX_ELT + 1];

    Deque(void) {
        front = MAX_ELT;
        back = MAX_ELT - 1;
    }

    void push_front(int x) {
        --front;
        deque[front] = x;
        return;
    }

    void push_back(int x) {
        ++back;
        deque[back] = x;
        return;
    }

    int pop_front(void) {
        if (back < front) {
            return ERROR;
        } else {
            ++front;
            return deque[front - 1];
        }
    }

    int pop_back(void) {
        if (back < front) {
            return ERROR;
        } else {
            --back;
            return deque[back+1];
        }
    }

    int size(void) {
        return back - front + 1;
    }

    int empty(void) {
        return front == back + 1;
    }

    int peek_front(void) {
        if (back < front) {
            return ERROR;
        } else {
            return deque[front];
        }
    }

    int peek_back(void) {
        if (back < front) {
            return ERROR;
        } else {
            return deque[back];
        }
    }
};


int main(void) {
    int n;
    scanf("%d", &n);

    Deque dq;
    for(int _ = 0; _ < n; ++_) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int elt;
            scanf("%d", &elt);
            dq.push_front(elt);
        } else if (cmd == "push_back") {
            int elt;
            scanf("%d", &elt);
            dq.push_back(elt);
        } else if (cmd == "pop_front") {
            printf("%d\n", dq.pop_front());
        } else if (cmd == "pop_back") {
            printf("%d\n", dq.pop_back());
        } else if (cmd == "size") {
            printf("%d\n", dq.size());
        } else if (cmd == "empty") {
            printf("%d\n", dq.empty());
        } else if (cmd == "front") {
            printf("%d\n", dq.peek_front());
        } else if (cmd == "back") {
            printf("%d\n", dq.peek_back());
        }
    }

    return EXIT_SUCCESS;
}

