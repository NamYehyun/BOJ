#include <iostream>
#include <vector>

using namespace std;


class Person {
public:
    int weight;
    int height;

    Person(int _weight, int _height) {
        weight = _weight;
        height = _height;
    }
};


int compare(Person p, Person q) {
    if (p.weight > q.weight && p.height > q.height) {
        return 1;
    }

    if (p.weight < q.weight && p.height < q.height) {
        return -1;
    }

    return 0;
}


int main(void) {
    int n;
    cin >> n;

    vector<Person> people;
    for (int i = 0; i < n; ++i) {
        int w, h;
        cin >> w >> h;

        people.push_back(Person(w, h));
    }

    for (auto p: people) {
        int rank = 1;
        for (auto q: people) {
            if (compare(p, q) < 0) {
                ++rank;
            }
        }

        cout << rank << ' ';
    }

    cout << endl;
    
    return EXIT_SUCCESS;
}

