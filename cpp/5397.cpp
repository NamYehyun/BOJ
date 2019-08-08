#include <iostream>

using namespace std;


class LinkedList {
public:
    class Node {
    public:
        char value;
        Node* prev;
        Node* next;

        Node(char _value): value(_value), prev(nullptr), next(nullptr) {};

        Node(char _value, Node* _prev, Node* _next): value(_value), prev(_prev), next(_next) {};
    };

    Node* curr;
    Node* head;
    Node* tail;

    LinkedList(void) {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;

        curr = head;
    }

    void insert(char value) {
        Node* new_node = new Node(value, curr, curr->next);

        curr->next->prev = new_node;
        curr->next = new_node;

        curr = new_node;

        return;
    }

    void remove(void) {
        if (curr == head || curr == tail) {
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        Node* tmp = curr;
        curr = curr->prev;

        delete tmp;

        return;
    }

    void move_left(void) {
        if (curr == head) {
            return;
        }

        curr = curr->prev;

        return;
    }

    void move_right(void) {
        if (curr->next == tail) {
            return;
        }

        curr = curr->next;

        return;
    }

    void print(void) {
        for (Node* node = head; node != tail; node = node->next) {
            if (node == head || node == tail) {
                continue;
            }
            cout << node->value;
        }
        cout << '\n';

        return;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;

    char c;
    while (cin.get(c) && c != '\n');

    while (num_test--) {
        string line;
        getline(cin, line);

        LinkedList ll;

        for (const char& c: line) {
            if (c == '<') {
                ll.move_left();
            } else if (c == '>') {
                ll.move_right();
            } else if (c == '-') {
                ll.remove();
            } else {
                ll.insert(c);
            }
        }

        ll.print();
    }


    return EXIT_SUCCESS;
}

