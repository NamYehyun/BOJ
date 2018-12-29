#include <iostream>

using namespace std;


class Node {
public:
    int id;
    Node* next;

    Node (int _id) {
        id = _id;
        next = nullptr;
    }
};

class CircularList {
public:
    Node* head;
    Node* tail;

    CircularList(void) {
        head = nullptr;
        tail = nullptr;
    }

    void append(Node* node) {
        if (head == nullptr) {
            head = node;
        }

        if (tail == nullptr) {
            tail = node;
        }

        tail->next = node;
        tail = node;
        tail->next = head;

        return;
    }

    Node* remove_nth_help(Node* curr, int idx) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (idx == 1) {
            Node* target = curr->next;
            if (target == curr) {
                tail = nullptr;
                return target;
            } else {
                curr->next = target->next;
                tail = curr;
                return target;
            }
        } else {
            return remove_nth_help(curr->next, idx-1);
        }
    }

    Node* remove_nth(int idx) {
        return remove_nth_help(tail, idx);
    }

    void print_help(Node* curr) {
        if (curr == nullptr) {
            return;
        } else {
            printf("%d ", curr->id);
            if (curr->next != tail) {
                print_help(curr->next);
            }
        }
    }
    
    void print(void) {
        printf("[ ");
        print_help(tail);
        printf("]\n");

        return;        
    }
};


int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    CircularList list;
    for (int i = 1; i <= n; ++i) {
        list.append(new Node(i));
    }

    // list.print();

    printf("<");
    for (int i = 1; i <= n; ++i) {
        Node* removed = list.remove_nth(m);
        printf("%d", removed->id);
        if (i != n) {
            printf(", ");
        }
        // printf("remove %d ", removed->id);
        // list.print();
    }
    printf(">\n");

    return EXIT_SUCCESS;
}

