#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Quiz {
public:
    int id;
    int score;

    Quiz(int _id, int _score) {
        id = _id;
        score = _score;
    }

    bool operator<(const Quiz& other) const {
        if (score == other.score) {
            return id < other.id;
        }

        return score < other.score;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<Quiz> quiz;
    for (int id = 1; id <= 8; ++id) {
        int score;
        cin >> score;

        quiz.emplace_back(id, score);
    }

    sort(quiz.begin(), quiz.end());

    int acc = 0;
    vector<int> ids;
    for (int i = 3; i < 8; ++i) {
        acc += quiz[i].score;
        ids.emplace_back(quiz[i].id);
    }

    sort(ids.begin(), ids.end());

    cout << acc << endl;
    for (int id: ids) {
        cout << id << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}

