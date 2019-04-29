#include <iostream>
#include <set>
#include <vector>

using namespace std;


class Node {
public:
    int id;
    set<Node*> adj_nodes;
    bool visited;

    Node(int _id): id(_id), visited(false) {};
};


bool match(Node* curr, Node* dst) {
    if (curr == dst) {
        return true;
    }

    curr->visited = true;

    for (Node* next: curr->adj_nodes) {
        if ((!next->visited) && match(next, dst)) {
            next->adj_nodes.insert(curr);
            curr->adj_nodes.erase(next);
            return true;
        }
    }

    return false;
}


int bi_match(vector<Node*>& domain, vector<Node*>& codomain) {
    Node* src = new Node(-1);
    for (Node* node: domain) {
        src->adj_nodes.insert(node);
    }

    Node* dst = new Node(-1);
    for (Node* node: codomain) {
        node->adj_nodes.insert(dst);
    }

    int cnt = 0;
    while (match(src, dst)) {
        for (Node* node: domain) {
            node->visited = false;
        }

        for (Node* node: codomain) {
            node->visited = false;
        } 

        ++cnt;
    }

    return cnt;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int num_cow, num_shed;
    cin >> num_cow >> num_shed;

    vector<Node*> cows;
    vector<Node*> sheds;

    for (int cow_id = 0; cow_id < num_cow; ++cow_id) {
        cows.push_back(new Node(cow_id));
    }

    for (int shed_id = 0; shed_id < num_shed; ++shed_id) {
        sheds.push_back(new Node(shed_id));
    }

    for (Node* cow: cows) {
        int num_adj;
        cin >> num_adj;
        for (int i = 0; i < num_adj; ++i) {
            int shed;
            cin >> shed;
            cow->adj_nodes.insert(sheds[shed-1]);
        }
    }

    cout << bi_match(cows, sheds) << endl;

    return EXIT_SUCCESS;
}

