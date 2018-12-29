#include <iostream>

using namespace std;


const int MAX_ELT = 10000;
const int ERROR = -1;


class Queue {
public:
    int front;
    int back;
    int queue[MAX_ELT + 10];

    Queue(void) {
        front = 0;
        back = 0;
    }

    void push(int x) {
        queue[back] = x;
        ++back;

        return;
    }

    int pop(void) {
        if (front == back) {
            return ERROR;
        } else {
            ++front;
            
            return queue[front - 1];
        }
    }

    int size(void) {
        return back - front;
    }

    bool empty(void) {
        return front == back;
    }

    int peek_front(void) {
        if (front == back) {
            return ERROR;
        } else {
            return queue[front];
        }
    }

    int peek_back(void) {
        if (front == back || back == 0) {
            return ERROR;
        } else {
            return queue[back - 1];
        }
    }
};


int main(void) {
    int n;
    scanf("%d", &n);

    Queue q;
    for (int _ = 0; _ < n; ++_) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int elt;
            scanf("%d", &elt);
            q.push(elt); 
        } else if (cmd == "pop") {
            printf("%d\n", q.pop());
        } else if (cmd == "size") {
            printf("%d\n", q.size());
        } else if (cmd == "empty") {
            printf("%d\n", q.empty());
        } else if (cmd == "front") {
            printf("%d\n", q.peek_front());
        } else if (cmd == "back") {
            printf("%d\n", q.peek_back());
        }
    }

    return EXIT_SUCCESS;
}

