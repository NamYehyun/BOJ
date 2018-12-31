#include <iostream>

using namespace std;


class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int _value) {
        value = _value;
    }
};

class CircularList {
public:
    Node* pos;

    CircularList(void) {
        pos = nullptr;
    }

    void append(Node* newNode) {
        if (pos == nullptr) {
            newNode->prev = newNode;
            newNode->next = newNode;
            pos = newNode;
        } else {
            newNode->prev = pos;
            newNode->next = pos->next;

            pos->next->prev = newNode;

            pos->next = newNode;
            if (pos->prev == pos) {
                pos->prev = newNode;
            }

            pos = newNode;
        }

        return;
    }

    void append(int n) {
        append(new Node(n));
    }

    int dist_prev(Node* curr, int n) {
        if (curr->value == n) {
            return 0;
        } else {
            return dist_prev(curr->prev, n) + 1;
        }
    }

    int dist_next(Node* curr, int n) {
        if (curr->value == n) {
            return 0;
        } else {
            return dist_next(curr->next, n) + 1;
        }
    }

    int remove_prev(Node* curr, int n) {
        if (curr->value == n) {
            Node* prev = curr->prev;
            Node* next = curr->next;

            prev->next = next;
            next->prev = prev;

            pos = next;

            delete curr;

            return 0;
        } else {
            return remove_prev(curr->prev, n) + 1;
        }
    }

    int remove_next(Node* curr, int n) {
        if (curr->value == n) {
            Node* prev = curr->prev;
            Node* next = curr->next;

            prev->next = next;
            next->prev = prev;

            pos = next;

            delete curr;

            return 0;
        } else {
            return remove_next(curr->next, n) + 1;
        }
    }

    int remove(int n) {
        int d_prev = dist_prev(pos, n);
        int d_next = dist_next(pos, n);
        if (d_prev <= d_next) {
            return remove_prev(pos, n);
        } else {
            return remove_next(pos, n);
        }
    }

    void print_help(Node* curr, bool flag) {
        if (curr == pos) {
            if (flag) {
                return;
            } else {
                flag = true;
            } 
        }

        printf("%d ", curr->value);
        print_help(curr->next, flag);

        return;
    }

    void print(void) {
        printf("[ ");
        print_help(pos, false);
        printf("]\n");

        return;
    }
};

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    CircularList list;
    for (int i = 1; i <= n; ++i) {
        list.append(i);
    }

    list.pos = list.pos->next;

    // list.print();
    
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int v;
        scanf("%d", &v);
        ans += list.remove(v);
        // list.print();
    }

    printf("%d\n", ans);

    return EXIT_SUCCESS;
}

