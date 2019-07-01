#include <functional>
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class SegTree {
public:
    const T NIL;
    int depth;
    int num_leaf;
    vector<T> tree;
    function<T(T, T)> aggregate;

    SegTree(vector<T> seq, T nil, function<T(T, T)>& _agg): NIL(nil), aggregate(_agg) {
        int num_elt = seq.size();

        depth = 1;
        num_leaf = 1;
        while (num_leaf < num_elt) {
            num_leaf *= 2;
            ++depth;
        }

        int num_node = 2*num_leaf - 1;
        tree.resize(num_node, NIL);

        for (int i = 0; i < num_elt; ++i) {
            tree[num_node-num_leaf+i] = seq[i];
        }

        for (int i = num_elt; i < num_leaf; ++i) {
            tree[num_node-num_leaf+i] = nil;
        }

        build();
    }

    T build(int curr, int curr_depth) {
        if (curr_depth < depth-1) {
            T l_child = build(2*curr+1, curr_depth+1);
            T r_child = build(2*curr+2, curr_depth+1);

            if (l_child == NIL) {
                tree[curr] = r_child;
            } else if (r_child == NIL) {
                tree[curr] = l_child;
            } else {
                tree[curr] = aggregate(l_child, r_child);
            }
        }

        return tree[curr];
    }

    void build(void) {
        build(0, 0);
        return;
    }

    T get(int lo, int hi, int curr, int curr_lo, int curr_hi) {
        if (lo <= curr_lo && curr_hi <= hi) {
            return tree[curr];
        }

        if (curr_hi < lo || hi < curr_lo) {
            return NIL;
        }

        int curr_mid = (curr_lo + curr_hi) / 2;
        T l_get = get(lo, hi, 2*curr+1, curr_lo, curr_mid);
        T r_get = get(lo, hi, 2*curr+2, curr_mid+1, curr_hi);

        if (l_get == NIL) {
            return r_get;
        } else if (r_get == NIL) {
            return l_get;
        } else {
            return aggregate(l_get, r_get);
        }
    }

    T get(int lo, int hi) {
        return get(lo, hi, 0, 0, num_leaf-1);
    }

    T update(int pos, T val, int curr, int curr_lo, int curr_hi) {
        if (curr_lo == pos && curr_hi == pos) {
            return tree[curr] = val;
        }

        if (pos < curr_lo || curr_hi < pos) {
            return tree[curr];
        }

        int curr_mid = (curr_lo + curr_hi) / 2;
        int l_update = update(pos, val, 2*curr+1, curr_lo, curr_mid);
        int r_update = update(pos, val, 2*curr+2, curr_mid+1, curr_hi);

        if (l_update == NIL) {
            return tree[curr] = r_update;
        } else if (r_update == NIL) {
            return tree[curr] = l_update;
        } else {
            return tree[curr] = aggregate(l_update, r_update);
        }
    }

    void update(int pos, T val) {
        update(pos, val, 0, 0, num_leaf-1);
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    function<int(int, int)> sum = [](int a, int b) -> int {
        return a + b;
    };

    int num_test;
    cin >> num_test;
    while (num_test--) {
        int num_book, num_query;
        cin >> num_book >> num_query;
        
        vector<int> exists(num_book+num_query, 1);
        for (int i = 0; i < num_query; ++i) {
            exists[i] = false;
        }

        vector<int> pos(num_book+1);
        for (int book = 1; book <= num_book; ++book) {
            pos[book] = book - 1 + num_query;
        }

        SegTree<int> book_tree(exists, 0, sum);

        int top = num_query - 1;
        for (int query = 0; query < num_query; ++query) {
            int book;
            cin >> book;

            cout << book_tree.get(0, pos[book]-1) << ' ';

            book_tree.update(pos[book], 0);
            book_tree.update(top, 1);
            pos[book] = top;
            --top;
        }
        cout << '\n';
    }

    return EXIT_SUCCESS;
}

