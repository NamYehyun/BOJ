#include <iostream>
#include <vector>

using namespace std;


const int INF = 0x7f7f7f7f;


class Node {
public:
    int id, dist;

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

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

	vector<vector<int>> adj_matrix(num_nodes+1, vector<int>(num_nodes+1, INF));
	for (int i = 0; i < num_edges; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		adj_matrix[x][y] = min(adj_matrix[x][y], w);
	}

    vector<Node*> nodes(num_nodes+1, nullptr);
    for (int id = 1; id <= num_nodes; ++id) {
        nodes[id] = new Node(id);
    }

    vector<Edge*> edges;
	for (int i = 1; i <= num_nodes; ++i) {
		for (int j = 1; j <= num_nodes; ++j) {
			if (adj_matrix[i][j] != INF) {
				edges.push_back(new Edge(nodes[i], nodes[j], adj_matrix[i][j]));
			}
		}
	}

    nodes[1]->dist = 0;
    for (int _ = 0; _ < num_nodes; ++_) {
        for (Edge* e: edges) {
            Node* src = e->src;
            Node* dst = e->dst;
            if ((src->dist != INF) && (dst->dist > src->dist + e->weight)) {
                dst->dist = src->dist + e->weight;
            }
        }
    }

    bool neg_cycle = false;
    for (Edge* e: edges) {
        Node* src = e->src;
        Node* dst = e->dst;
        if ((src->dist != INF) && (dst->dist > src->dist + e->weight)) {
            neg_cycle = true;
        }
    }

    if (neg_cycle) {
        cout << -1 << '\n';
    } else {
        for (int id = 2; id <= num_nodes; ++id) {
            int dist = nodes[id]->dist;
            cout << (dist != INF ? dist : -1) << '\n';
        }
    }

    return EXIT_SUCCESS;
}

