#include <vector>


long long sum(std::vector<int>& a) {
    long long acc = 0;
    for (const int& num: a) {
        acc += static_cast<long long>(num);
    }

    return acc;

}

