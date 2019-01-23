#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


class Node {
public:
    int id;
    int level;
    int pos;
    Node* parent;
    Node* l_child;
    Node* r_child;

    Node(int _id, int _level, int _pos, Node* _parent, Node* _l_child, Node* _r_child) {
        id = _id;
        level = _level;
        pos = _pos;
        parent = _parent;
        l_child = _l_child;
        r_child = _r_child;
    }
};


class Span {
public:
    int min;
    int max;

    Span(int _min, int _max) {
        min = _min;
        max = _max;
    }

    int length(void) {
        return max - min + 1;
    }
};


Node* find_root(Node* n) {
    return (n->parent == nullptr) ? n : find_root(n->parent);
}


void traverse(Node* root, int level) {
    static int pos = 0;

    if (root == nullptr) {
        return;
    }

    traverse(root->l_child, level+1);

    root->level = level;
    root->pos = pos;
    ++pos;

    traverse(root->r_child, level+1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<Node> nodes;
    for (int i = 0; i <= n; ++i) {
        nodes.push_back(Node(i, -1, -1, nullptr, nullptr, nullptr));
    }

    for (int _ = 0; _ < n; ++_) {
        int p, l, r;
        cin >> p >> l >> r;

        if (l != -1) {
            nodes[p].l_child = &(nodes[l]);
            nodes[l].parent = &(nodes[p]);
        }

        if (r != -1) {
            nodes[p].r_child = &(nodes[r]);
            nodes[r].parent = &(nodes[p]);
        }
    }

    Node* root = find_root(&(nodes[1]));

    traverse(root, 1);

    int depth = 0;
    for (Node n: nodes) {
        if (depth < n.level) {
            depth = n.level;
        }
    }

    vector<Span> span;
    for (int i = 0; i <= depth; ++i) {
        span.push_back(Span(INF, -INF));
    }

    for (Node n: nodes) {
        if (n.level < 0) {
            continue;
        }

        if (n.pos < span[n.level].min) {
            span[n.level].min = n.pos;
        }

        if (n.pos > span[n.level].max) {
            span[n.level].max = n.pos;
        }
    }

    int max_level = 0;
    int max_length = 0;
    for (int level = 1; level <= depth; ++level) {
        int length = span[level].length();
        if (max_length < length) {
            max_level = level;
            max_length = length;
        }
    }

    cout << max_level << ' ' << max_length << endl;

    return EXIT_SUCCESS;
}

