#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Member {
public:
    int age;
    string name;

    Member(int _age, string _name): age(_age), name(_name) {}

    bool operator<(const Member& other) const {
        return age < other.age;
    }
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Member> members;
    for (int i = 0; i < n; ++i) {
        int age;
        string name;
        cin >> age >> name;
        members.emplace_back(age, name);
    }

    stable_sort(members.begin(), members.end());

    for (const Member& member: members) {
        cout << member.age << ' ' << member.name << '\n';
    }

    return EXIT_SUCCESS;
}

