#include <iostream>
#include <vector>

using namespace std;


class SegTree {
public:
    int num_elt;
    int num_leaf;
    int num_node;
    vector<long long> tree;

    inline int ith_leaf(int idx) {
        return num_leaf - 1 + idx;
    }

    int left(int idx) {
        return 2*idx + 1;
    }

    inline int right(int idx) {
        return 2*idx + 2;
    }

    inline int parent(int idx) {
        return (idx - 1) / 2;
    }

    SegTree(int _num_elt, vector<long long>& elts): num_elt(_num_elt) {
        num_leaf = 1;
        while (num_leaf < num_elt) {
            num_leaf *= 2;
        }

        num_node = 2*num_leaf - 1;

        tree.resize(num_node, 0);

        for (int i = 0; i < num_elt; ++i) {
            tree[ith_leaf(i)] = elts[i];
        }

        int from = parent(ith_leaf(0));
        int to = parent(ith_leaf(num_leaf-1));
        while (true) {
            for (int i = from; i <= to; ++i) {
                tree[i] = tree[left(i)] + tree[right(i)];
            }

            if (from == to) {
                break;
            }

            from = parent(from);
            to = parent(to);
        }
    }

    void replace(int idx, long long val) {
        int curr = ith_leaf(idx);
        long long diff = val - tree[curr];

        while (true) {
            tree[curr] += diff;
            
            if (curr == 0) {
                break;
            }

            curr = parent(curr);
        }

        return;
    }

    long long sum_help(int from, int to, int node, int node_from, int node_to) {
        if (from <= node_from && node_to <= to) {
            return tree[node];
        }

        if (to < node_from || node_to < from) {
            return 0;
        }

        int node_mid = (node_from + node_to) / 2;
        return sum_help(from, to, left(node), node_from, node_mid) + sum_help(from, to, right(node), node_mid+1, node_to);
    }

    long long sum(int from, int to) {
        return sum_help(from, to, 0, 0, num_leaf-1);
        
    }

    void print(void) {
        int front = 0;
        int rear = 0;
        while (rear - front + 1 <= num_leaf) {
            for (int i = 0; i < num_leaf-(rear-front+1); ++i) {
                cout << ' ';
            }
            for (int i = front; i <= rear; ++i) {
                cout << tree[i] << ' ';
            }
            cout << endl;

            front = 2*front + 1;
            rear = 2*rear + 2;
        }
        cout << endl;
    }    
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    SegTree seg_tree(n, seq);

    for (int i = 0; i < m + k; ++i) {
        long long cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 1) {
            seg_tree.replace(static_cast<int>(a)-1, b);
        } else if (cmd == 2) {
            cout << seg_tree.sum(static_cast<int>(a)-1, static_cast<int>(b)-1) << '\n';
        }
    }

    return EXIT_SUCCESS;
}

