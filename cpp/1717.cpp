#include <iostream>
#include <vector>

using namespace std;


class Node {
public:
    int id;
    int size;
    Node* parent;

    Node(int _id): id(_id), size(1), parent(this) {}
};


Node* root_of(Node* curr) {
    if (curr->parent == curr) {
        return curr;
    }

    return curr->parent = root_of(curr->parent);
}


Node* merge(Node* u, Node* v) {
    Node* ru = root_of(u);
    Node* rv = root_of(v);

    if (ru == rv) {
        return ru;
    }

    if (ru->size < rv->size) {
        ru->parent = rv;
        rv->size += ru->size;
        return rv;
    } else {
        rv->parent = ru;
        ru->size += rv->size;
        return ru;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_node, num_query;
    cin >> num_node >> num_query;

    vector<Node*> nodes(num_node+1, nullptr);
    for (int i = 0; i <= num_node; ++i) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < num_query; ++i) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 0) {
            merge(nodes[u], nodes[v]);
        } else {
            cout << (root_of(nodes[u]) == root_of(nodes[v]) ? "YES" : "NO") << '\n';
        }
    }

    return EXIT_SUCCESS;
}

