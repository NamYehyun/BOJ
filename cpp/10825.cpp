#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Student {
public:
    string name;
    int kor, eng, math;

    Student(string _name, int _kor, int _eng, int _math): name(_name), kor(_kor), eng(_eng), math(_math) {}

    bool operator<(const Student& other) const {
        if (kor == other.kor && eng == other.eng && math == other.math) {
            return name < other.name;
        }

        if (kor == other.kor && eng == other.eng) {
            return math > other.math;
        }

        if (kor == other.kor) {
            return eng < other.eng;
        }

        return kor > other.kor;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        students.emplace_back(name, kor, eng, math);
    }

    sort(students.begin(), students.end());

    for (const Student& student: students) {
        cout << student.name << '\n';
    }

    return EXIT_SUCCESS;
}

