#include <iostream>
#include <vector>

using namespace std;


const int NIL = 0;
const int INF = 0x7f7f7f7f;


class Queue {
private:
    const int size = 10000;
    int front, rear;
    vector<int> queue;

public:
    Queue(void): front(0), rear(0) {
        queue.resize(size);
    }

    void enqueue(int elt) {
        queue[rear] = elt;
        rear = (rear + 1) % size;
        return;
    }

    int dequeue(void) {
        int elt = queue[front];
        front = (front + 1) % size;
        return elt;
    }

    bool empty(void) {
        return (front == rear);
    }
};


bool bfs(vector<int>& set_A, vector<int>& dist, vector<int>& pair_A, vector<int>& pair_B, vector<vector<int>>& adj_list) {
    Queue q;
    for (int a: set_A) {
        if (pair_A[a] == NIL) {
            dist[a] = 0;
            q.enqueue(a);
        } else {
            dist[a] = INF;
        }
    }

    dist[NIL] = INF;
    while (!q.empty()) {
        int a = q.dequeue();
        if (dist[a] < dist[NIL]) {
            for (int b: adj_list[a]) {
                if (dist[pair_B[b]] == INF) {
                    dist[pair_B[b]] = dist[a] + 1;
                    q.enqueue(pair_B[b]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}


bool dfs(int a, vector<int>& dist, vector<int>& pair_A, vector<int>& pair_B, vector<vector<int>>& adj_list) {
    if (a != NIL) {
        for (int b: adj_list[a]) {
            if ((dist[pair_B[b]] == dist[a] + 1) && dfs(pair_B[b], dist, pair_A, pair_B, adj_list)) {
                pair_A[a] = b;
                pair_B[b] = a;
                return true;
            }
        }

        dist[a] = INF;
        return false;
    }

    return true;
}


int hopcroft_karp(vector<int>& set_A, vector<int>& set_B, vector<vector<int>>& adj_list) {
    const int size_A = set_A.size();
    const int size_B = set_B.size();

    vector<int> pair_A(size_A + 1, NIL);
    vector<int> pair_B(size_B + 1, NIL);
    vector<int> dist(size_A + 1, INF);

    int matching = 0;
    while (bfs(set_A, dist, pair_A, pair_B, adj_list)) {
        for (int a: set_A) {
            if ((pair_A[a] == NIL) && dfs(a, dist, pair_A, pair_B, adj_list)) {
                ++matching;
            }
        }
    }

    return matching;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_test;
    cin >> num_test;

    while (num_test--) {
        int num_book, num_stu;
        cin >> num_book >> num_stu;

        vector<int> students(num_stu);
        for (int id = 1; id <= num_stu; ++id) {
            students[id-1] = id;
        }

        vector<int> books(num_book);
        for (int id = 1; id <= num_book; ++id) {
            books[id-1] = id;
        }

        vector<vector<int>> adj_list(num_stu + 1, vector<int>());
        for (int stu = 1; stu <= num_stu; ++stu) {
            int from, to;
            cin >> from >> to;
            for (int book = from; book <= to; ++book) {
                adj_list[stu].push_back(book);
            }
        }

        cout << hopcroft_karp(students, books, adj_list) << endl;
    }

    return EXIT_SUCCESS;
}

