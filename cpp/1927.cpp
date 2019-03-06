#include <iostream>
#include <vector>

using namespace std;


inline void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;

    return;
}


class MinHeap {
public:
    int size;
    vector<int> heap;

    MinHeap(void) {
        size = 0;
        heap.resize(100001);
    }

    inline int left(int idx) {
        return 2*idx + 1;
    }

    inline int right(int idx) {
        return 2*idx + 2;
    }

    inline int parent(int idx) {
        return (idx - 1)/2;
    }

    void insert(int n) {
        heap[size] = n;
        ++size;

        int curr = size - 1;
        while (true) {
            int par = parent(curr);
            if (heap[par] <= heap[curr]) {
                break;
            }

            swap(heap[par], heap[curr]);
            curr = par;
        }


        return;
    }

    int extract(void) {
        if (size == 0) {
            return 0;
        }

        int min_value = heap[0];
        heap[0] = heap[size-1];
        --size;

        int curr = 0;
        while (true) {
            int lc = (left(curr) < size) ? left(curr) : curr;
            int rc = (right(curr) < size) ? right(curr) : curr;

            int next = (heap[lc] < heap[rc]) ? lc : rc;

            if (heap[curr] <= heap[next]) {
                break;
            }

            swap(heap[curr], heap[next]);
            curr = next;
        }

        return min_value;
    }

    bool empty(void) {
        return size == 0;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    MinHeap heap;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x) {
            heap.insert(x);
        } else {
            cout << heap.extract() << '\n';
        }
    }

    return EXIT_SUCCESS;
}

