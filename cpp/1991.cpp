#include <iostream>
#include <map>

using namespace std;


class Node {
public:
    char id;
    Node* left;
    Node* right;

    Node(char _id) {
        id = _id;
        left = nullptr;
        right = nullptr;
    }
};


class Tree {
public:
    Node* root;

    Tree(void) {
        root = nullptr;
    }

    Tree(Node* node) {
        root = node;
    }

    void print_preorder_rec(Node* curr) {
        if (curr != nullptr) {
            cout << curr->id;
            print_preorder_rec(curr->left);
            print_preorder_rec(curr->right);
        }

        return;
    }

    void print_inorder_rec(Node* curr) {
        if (curr != nullptr) {
            print_inorder_rec(curr->left);
            cout << curr->id;
            print_inorder_rec(curr->right);
        }

        return;
    }

    void print_postorder_rec(Node* curr) {
        if (curr != nullptr) {
            print_postorder_rec(curr->left);
            print_postorder_rec(curr->right);
            cout << curr->id;
        }
    }

    void print_preorder(void) {
        print_preorder_rec(root);
        cout << endl;
        
        return;
    }

    void print_inorder(void) {
        print_inorder_rec(root);
        cout << endl;
        
        return;
    }

    void print_postorder(void) {
        print_postorder_rec(root);
        cout << endl;
        
        return;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<char, Node*> id_to_node;
    for (int i = 0; i < 26; ++i) {
        char id = 'A' + i;
        Node* new_node = new Node(id);
        id_to_node[id] = new_node;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char par, left, right;
        cin >> par >> left >> right;

        if (left != '.') {
            id_to_node[par]->left = id_to_node[left];
        }

        if (right != '.') {
            id_to_node[par]->right = id_to_node[right];
        }
    }

    Tree tree(id_to_node['A']);

    tree.print_preorder();
    tree.print_inorder();
    tree.print_postorder();

    return EXIT_SUCCESS;
}

