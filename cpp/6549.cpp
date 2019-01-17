#include <iostream>
#include <vector>

using namespace std;


const bool DEBUG = false;
const int INF = 0x7fffffff;


inline int value(vector<int>& array, int index) {
    return (0 <= index && index < static_cast<int>(array.size())) ? array[index] : INF;
}


int init(vector<int>& histogram, vector<int>& seg_tree, int node, int start, int end) {
    if (start == end) {
        return seg_tree[node] = start;
    }

    int mid = (start + end) / 2;
    int idx1 = init(histogram, seg_tree, 2*node+1, start, mid);
    int idx2 = init(histogram, seg_tree, 2*node+2, mid+1, end);

    if (value(histogram, idx1) <= value(histogram, idx2)) {
        return seg_tree[node] = idx1;
    } else {
        return seg_tree[node] = idx2;
    }
}


int min_index(vector<int>& histogram, int idx_start, int idx_end, vector<int>& seg_tree, int node, int node_start, int node_end) {
    if (node_end < idx_start || idx_end < node_start) {
        return -1;
    }

    if (idx_start <= node_start && node_end <= idx_end) {
        return seg_tree[node];
    }

    int node_mid = (node_start + node_end) / 2;
    int idx1 = min_index(histogram, idx_start, idx_end, seg_tree, 2*node+1, node_start, node_mid);
    int idx2 = min_index(histogram, idx_start, idx_end, seg_tree, 2*node+2, node_mid+1, node_end);

    return (value(histogram, idx1) <= value(histogram, idx2)) ? idx1 : idx2;
}


long long max_area(vector<int>& histogram, int idx_start, int idx_end, vector<int>& seg_tree, int num_leaves) {
    if (idx_end == idx_start) {
        return static_cast<long long>(histogram[idx_start]);
    }

    int idx_min = min_index(histogram, idx_start, idx_end, seg_tree, 0, 0, num_leaves-1);

    long long width = static_cast<long long>(idx_end - idx_start + 1);
    long long height = static_cast<long long>(histogram[idx_min]);

    long long area = width * height;
    if (idx_start < idx_min) {
        long long area_left = max_area(histogram, idx_start, idx_min-1, seg_tree, num_leaves);
        if (area < area_left) {
            area = area_left;
        }
    }

    if (idx_min < idx_end) {
        long long area_right = max_area(histogram, idx_min+1, idx_end, seg_tree, num_leaves);
        if (area < area_right) {
            area = area_right;
        }
    }

    return area;
}


long long solve(vector<int>& histogram) {
    int n = histogram.size();

    int num_nodes = 0;
    int num_leaves = 1;
    while (true) {
        num_nodes += num_leaves;

        if (n <= num_leaves) {
            break;
        }

        num_leaves *= 2;
    }

    vector<int> seg_tree(num_nodes);
    init(histogram, seg_tree, 0, 0, num_leaves - 1);

    return max_area(histogram, 0, n-1, seg_tree, num_leaves);
}


int main(void) {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> histogram(n);

        for (int i = 0; i < n; ++i) {
            cin >> histogram[i];
        }

        cout << solve(histogram) << '\n';
    }

    return EXIT_SUCCESS;
}

