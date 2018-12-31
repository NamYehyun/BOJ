#include <iostream>
#include <sstream>

using namespace std;


const bool SUCCESS = true;
const bool FAILURE = false;


class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int _value) {
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    Node* tail;
    bool rev;

    List(void) {
        head = nullptr;
        tail = nullptr;
        rev = false;
    }

    void append(Node* new_node) {
        if (head == nullptr || tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;

            tail = new_node;
        }

        return;        
    }

    void append(int n) {
        append(new Node(n));
        return;
    }

    void reverse(void) {
        rev = !rev;
        return;
    }

    bool discard_head(void) {
        if (head == nullptr) {
            return FAILURE;
        } else {
            Node* new_head = head->next;
            if (new_head != nullptr) {
                new_head->prev = nullptr;
            }

            delete head;

            head = new_head;
            if (head == nullptr) {
                tail = nullptr;
            }

            return SUCCESS;
        }
    };

    bool discard_tail(void) {
        if (tail == nullptr) {
            return FAILURE;
        } else {
            Node* new_tail = tail->prev;
            if (new_tail != nullptr) {
                new_tail->next = nullptr;
            }

            delete tail;

            tail = new_tail;
            if (tail == nullptr) {
                head = nullptr;
            }

            return SUCCESS;
        }
    }

    bool discard(void) {
        if (rev) {
            return discard_tail();
        } else {
            return discard_head();
        }
    }

    void print_head(Node* curr) {
        if (curr == nullptr) {
            return;
        } else {
            if (curr == head) {
                printf("%d", curr->value);
            } else {
                printf(",%d", curr->value);
            }
            
            print_head(curr->next);
            return;
        }
    }

    void print_tail(Node* curr) {
        if (curr == nullptr) {
            return;
        } else {
            if (curr == tail) {
                printf("%d", curr->value);
            } else {
                printf(",%d", curr->value);
            }
            
            print_tail(curr->prev);
            return;
        }
    }

    void print(void) {
        printf("[");
        if (rev) {
            print_tail(tail);
        } else {
            print_head(head);
        }
        printf("]\n");
        
        return;
    }
};


int main(void) {
    int t;
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        List list;
        
        string cmd;
        cin >> cmd;

        int n;
        scanf("%d", &n);

        string seq;
        cin >> seq;
        seq = seq.substr(1, seq.length()-2);

        stringstream ss(seq);

        int num;
        while (ss >> num) {
            list.append(num);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }

        int length = cmd.length();
        bool error = false;
        for (int i = 0; i < length; ++i) {
            char c = cmd[i];
            if (c == 'R') {
                list.reverse();
            } else if (c == 'D') {
                if (list.discard() == FAILURE) {
                    error = true;
                    break;
                }
            }
        }

        if (error) {
            printf("error\n");
        } else {
            list.print();
        }
    }
    
    return EXIT_SUCCESS;
}

