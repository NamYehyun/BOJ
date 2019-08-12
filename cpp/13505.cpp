#include <iostream>
#include <map>
#include <vector>

using namespace std;


class Trie {
public:
    class Node {
    public:
        map<char, Node*> next;

        Node(void) {
            next['0'] = nullptr;
            next['1'] = nullptr;
        }
    };

    Node* root;

    Trie(void) {
        root = new Node();
    }

    void insert(Node* curr, string& str, int lo, int hi) {
        if (lo > hi) {
            return;
        }

        if (curr->next[str[lo]] == nullptr) {
            curr->next[str[lo]] = new Node();
        }

        insert(curr->next[str[lo]], str, lo+1, hi);
    }

    void insert(string& str) {
        insert(root, str, 0, str.length()-1);
    }

    string query(Node* curr, string& str, int lo, int hi) {
        if (lo > hi) {
            return "";
        }

        char bit = '0' + '1' - str[lo];
        if (curr->next[bit] != nullptr) {
            return "1" + query(curr->next[bit], str, lo+1, hi);
        } else {
            return "0" + query(curr->next[str[lo]], str, lo+1, hi);
        }
    }

    string query(string& str) {
        return query(root, str, 0, str.length()-1);
    }
};


inline string to_binary(int n) {
    string ret = "";

    for (int bit = 0; bit < 32; ++bit) {
        ret = static_cast<char>(n % 2 + '0') + ret;
        n /= 2;
    }

    return ret;
}


inline int to_int(string& str) {
    int ret = 0;

    for (const auto& s: str) {
        ret *= 2;
        ret += (s == '0' ? 0 : 1);
    }

    return ret;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    Trie trie;
    for (auto& s: seq) {
        string binary = to_binary(s);
        trie.insert(binary);
    }

    int ans = 0;
    for (auto& s: seq) {
        string binary = to_binary(s);
        string result = trie.query(binary);

        ans = max(ans, to_int(result));
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

