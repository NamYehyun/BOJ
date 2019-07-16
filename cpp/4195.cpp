#include <iostream>
#include <map>
#include <vector>

using namespace std;


class Node {
public:
    int id;
    int size;
    Node* parent;

    Node(int _id): id(_id), size(1), parent(this) {};
};


Node* root(Node* u) {
    if (u->parent == u) {
        return u;
    } else {
        return u->parent = root(u->parent);
    }
}


Node* merge(Node* u, Node* v) {
    Node* root_u = root(u);
    Node* root_v = root(v);

    if (root_u == root_v) {
        return root_u;
    }

    if (root_u->size > root_v->size) {
        root_v->parent = root_u;
        root_u->size += root_v->size;

        return root_u;
    } else {
        root_u->parent = root_v;
        root_v->size += root_u->size;

        return root_v;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int num_query;
        cin >> num_query;

        int next_id = 0;
        map<string, Node*> hash;
        for (int query = 0; query < num_query; ++query) {
            string name_u, name_v;
            cin >> name_u >> name_v;

            if (hash.find(name_u) == hash.end()) {
                hash[name_u] = new Node(next_id++);
            }

            if (hash.find(name_v) == hash.end()) {
                hash[name_v] = new Node(next_id++);
            }

            Node* u = hash[name_u];
            Node* v = hash[name_v];
            Node* r = merge(u, v);

            cout << r->size << '\n';
        }
    }

    return EXIT_SUCCESS;
}

