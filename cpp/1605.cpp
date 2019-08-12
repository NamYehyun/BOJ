#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Node {
public:
    int index, rank, next_rank;

    Node(int _index, int _rank, int _next_rank) {
        index = _index;
        rank = _rank;
        next_rank = _next_rank;
    }

    bool operator<(const Node& other) const {
        if (rank == other.rank) {
            return next_rank < other.next_rank;
        }

        return rank < other.rank;
    }
};


void set_suffix_array(string& s, vector<int>& suffix_array) {
    const int length = static_cast<int>(s.length());
    suffix_array.reserve(length);

    vector<Node> nodes;
    for (int i = 0; i < length; ++i) {
        nodes.emplace_back(i, s[i]-'a', ((i+1 < length) ? s[i+1]-'a' : -1));
    }

    sort(nodes.begin(), nodes.end());

    vector<int> ind(length, -1);
    for (int len = 4; len < 2*length; len *= 2) {
        int rank = 0;
        int prev_rank = nodes[0].rank;
        nodes[0].rank = rank;
        ind[nodes[0].index] = 0;

        for (int i = 1; i < length; ++i) {
            if (!(nodes[i].rank == prev_rank && nodes[i].next_rank == nodes[i-1].next_rank)) {
                ++rank;
            }
            
            prev_rank = nodes[i].rank;
            nodes[i].rank = rank;
            ind[nodes[i].index] = i;
        }

        for (int i = 0; i < length; ++i) {
            int next_index = nodes[i].index + len/2;
            nodes[i].next_rank = (next_index < length) ? nodes[ind[next_index]].rank : -1;
        }

        sort(nodes.begin(), nodes.end());
    }

    for (Node n: nodes) {
        suffix_array.push_back(n.index);
    }

    return;
}


void set_lcp_array(string& s, vector<int>& suffix_array, vector<int>& lcp_array) {
    const int length = static_cast<int>(s.length());
    lcp_array.resize(length, 0);

    vector<int> inv_suffix_array(length);
    for (int i = 0; i < length; ++i) {
        inv_suffix_array[suffix_array[i]] = i;
    }

    int prev = 0;
    for (int i = 0; i < length; ++i) {
        if (inv_suffix_array[i] == length-1) {
            prev = 0;
        } else {
            int j = suffix_array[inv_suffix_array[i]+1];
            while (i+prev < length && j+prev < length && s[i+prev] == s[j+prev]) {
                ++prev;
            }

            lcp_array[inv_suffix_array[i]+1] = prev;

            if (prev > 0) {
                --prev;
            }
        }
    }

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int length;
    cin >> length;

    string s;
    cin >> s;

    vector<int> suffix_array;
    vector<int> lcp_array;

    set_suffix_array(s, suffix_array);
    set_lcp_array(s, suffix_array, lcp_array);

    int ans = 0;
    for (int i = 1; i < length; ++i) {
        ans = max(ans, lcp_array[i]);
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

