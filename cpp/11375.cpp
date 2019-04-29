#include <iostream>
#include <set>
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


bool bfs(vector<int>& U, vector<int>& dist, vector<int>& pair_U, vector<int>& pair_V, vector<vector<int>>& adj_list) {
    Queue q;
    for (int u: U) {
        if (pair_U[u] == NIL) {
            dist[u] = 0;
            q.enqueue(u);
        } else {
            dist[u] = INF;
        }
    }

    dist[NIL] = INF;
    while (!q.empty()) {
        int u = q.dequeue();
        if (dist[u] < dist[NIL]) {
            for (int v: adj_list[u]) {
                if (dist[pair_V[v]] == INF) {
                    dist[pair_V[v]] = dist[u] + 1;
                    q.enqueue(pair_V[v]);
                }
            }
        }
    }

    return (dist[NIL] != INF);
}


bool dfs(int u, vector<int>& dist, vector<int>& pair_U, vector<int>& pair_V, vector<vector<int>>& adj_list) {
    if (u != NIL) {
        for (int v: adj_list[u]) {
            if (dist[pair_V[v]] == dist[u] + 1) {
                if (dfs(pair_V[v], dist, pair_U, pair_V, adj_list)) {
                    pair_V[v] = u;
                    pair_U[u] = v;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }

    return true;
}


int hopcroft_karp(vector<int>& U, vector<int>& V, vector<vector<int>>& adj_list) {
    const int size_U = U.size();
    const int size_V = V.size();

    vector<int> pair_U(size_U + 1, NIL);
    vector<int> pair_V(size_V + 1, NIL);
    vector<int> dist(size_U + 1, INF);

    int matching = 0;
    while (bfs(U, dist, pair_U, pair_V, adj_list)) {
        for (int u: U) {
            if (pair_U[u] == NIL) {
                if (dfs(u, dist, pair_U, pair_V, adj_list)) {
                    ++matching;
                }
            }
        }
    }

    return matching;
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int num_worker, num_job;
    cin >> num_worker >> num_job;

    vector<int> workers(num_worker);
    for (int worker_id = 1; worker_id <= num_worker; ++worker_id) {
        workers[worker_id-1] = worker_id;
    }

    vector<int> jobs(num_job);
    for (int job_id = 1; job_id < num_job; ++job_id) {
        jobs[job_id-1] = job_id;
    }

    vector<vector<int>> adj_list(num_worker+1, vector<int>());
    for (int worker: workers) {
        int num_choice;
        cin >> num_choice;
        for (int i = 0; i < num_choice; ++i) {
            int job;
            cin >> job;
            adj_list[worker].push_back(job);
        }
    }

    cout << hopcroft_karp(workers, jobs, adj_list) << endl;

    return EXIT_SUCCESS;
}

