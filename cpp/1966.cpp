#include <iostream>

using namespace std;


const int MAX_N = 100;


class Paper {
public:
    int id;
    int importance;

    Paper(int _id, int _importance) {
        id = _id;
        importance = _importance;
    }
};

class PrinterQueue {
public:
    int front;
    int rear;
    Paper* queue[MAX_N * MAX_N];

    PrinterQueue(void) {
        front = 0;
        rear = 0;
    }

    void enqueue(Paper* elt) {
        queue[rear] = elt;
        ++rear;
        return;
    }

    Paper* dequeue(void) {
        if (front == rear) {
            return NULL;
        } else {
            ++front;
            return queue[front - 1];
        }
    }

    int print(void) {
        Paper* p = dequeue();
        for (int i = front; i < rear; ++i) {
            if (p->importance < queue[i]->importance) {
                enqueue(p);
                return print();
            }
        }

        return p->id;
    }
};


int main(void) {
    int t;
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int n, target_id;
        scanf("%d%d", &n, &target_id);

        PrinterQueue q;
        for (int id = 0; id < n; ++id) {
            int importance;
            scanf("%d", &importance);
            q.enqueue(new Paper(id, importance));
        }

        for (int xth = 1; xth <= n; ++xth) {
            int printed_id = q.print();
            if (target_id == printed_id) {
                printf("%d\n", xth);
                break;
            }
        }
    }
    
    return EXIT_SUCCESS;
}

