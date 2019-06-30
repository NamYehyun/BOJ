#include <functional> 
#include <iostream>
#include <vector>

using namespace std;

typedef long long node_t;

const node_t INF = 0x7f7f7f7f7f7f7f7f; 
 
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
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 

    int num_node, num_query;
    cin >> num_node >> num_query;
     
    vector<node_t> seq(num_node);
    for (int i = 0; i < num_node; ++i) {
        cin >> seq[i]; 
    }

    function<node_t(node_t, node_t)> min = [](node_t a, node_t b) -> node_t {
        return (a < b) ? a : b; 
    };

    function<node_t(node_t, node_t)> max = [](node_t a, node_t b) -> node_t { 
        return (a > b) ? a : b;
    };

    SegTree<node_t> min_tree(seq, INF, min);
    SegTree<node_t> max_tree(seq, -INF, max);

    for (int i = 0; i < num_query; ++i) {
        int lo, hi;
        cin >> lo >> hi; 
        cout << min_tree.get(lo-1, hi-1) << ' ' << max_tree.get(lo-1, hi-1) << '\n';
    }

    return EXIT_SUCCESS;
} 

