#include <iostream>
#include <vector>

using namespace std;


class Node {
public:
    int id, x, y, r;

    Node* parent;
    int height;

    Node(int _id, int _x, int _y, int _r) {
        id = _id;
        x = _x;
        y = _y;
        r = _r;
        
        parent = nullptr;
        height = 1;
    }
};


inline int sq(int n) {
    return n * n;
}

bool adjacent(Node* n1, Node* n2) {
    return sq(n1->x - n2->x) + sq(n1->y - n2->y) <= sq(n1->r + n2->r);
}


Node* find(Node* n) {
    return (n->parent == nullptr) ? n : (n->parent = find(n->parent));
}

void unite(Node* n1, Node* n2) {
    Node* r1 = find(n1);
    Node* r2 = find(n2);

    if (r1 == r2) {
        return;
    }

    Node* root = (r1->height > r2->height) ? r1 : r2;
    Node* leaf = (root == r2) ? r1 : r2;

    leaf->parent = root;
    root->height = (root->height > leaf->height+1) ? root->height : leaf->height+1;

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Node*> nodes;
        for (int i = 0; i < n; ++i) {
            int x, y, r;
            cin >> x >> y >> r;

            nodes.push_back(new Node(i, x, y, r));
        }

        for (Node* node1: nodes) {
            for (Node* node2: nodes) {
               if (node1 == node2) {
                   continue;
               } 

               if (adjacent(node1, node2)) {
                   unite(node1, node2);
               }
            }
        }

        int cnt = 0;
        for (Node* node: nodes) {
            if (find(node) == node) {
                ++cnt;
            }
        }

        cout << cnt << '\n';

        for (Node* node: nodes) {
            delete node;
        }
    }

    return EXIT_SUCCESS;
}

