#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


class Node;
class Edge;

class Node {
public:
    int id;
    int dist;

    Node(int _id) {
        id = _id;
        dist = INF;
    }
};

class Edge {
public:
    Node* src;
    Node* dst;
    int weight;

    Edge(Node* _src, Node* _dst, int _weight) {
        src = _src;
        dst = _dst;
        weight = _weight;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int num_nodes, num_roads, num_warps;
        cin >> num_nodes >> num_roads >> num_warps;

        vector<Node*> nodes(num_nodes+1, nullptr);
        for (int i = 1; i <= num_nodes; ++i) {
            nodes[i] = new Node(i);
        }

        vector<Edge*> edges;
        for (int i = 0; i < num_roads; ++i) {
            int x, y, w;
            cin >> x >> y >> w;

            Edge* edge;
           
            edge = new Edge(nodes[x], nodes[y], w);
            edges.push_back(edge);

            edge = new Edge(nodes[y], nodes[x], w);
            edges.push_back(edge);
        }

        for (int i = 0; i < num_warps; ++i) {
            int x, y, w;
            cin >> x >> y >> w;

            Edge* edge = new Edge(nodes[x], nodes[y], -w);
            edges.push_back(edge);
        }

        nodes[1]->dist = 0;
        for (int i = 1; i <= num_nodes; ++i) {
            for (Edge* e: edges) {
                Node* src = e->src;
                Node* dst = e->dst;
                if (dst->dist > src->dist + e->weight) {
                    dst->dist = src->dist + e->weight;
                }
            }
        }

        bool neg_cycle = false;
        for (Edge* e: edges) {
            Node* src = e->src;
            Node* dst = e->dst;
            if (dst->dist > src->dist + e->weight) {
                neg_cycle = true;
            }
        }

        cout << (neg_cycle ? "YES\n" : "NO\n");

        for (Node* node: nodes) {
            delete node;
        }

        for (Edge* edge: edges) {
            delete edge;
        }
    }

    return EXIT_SUCCESS;
}

