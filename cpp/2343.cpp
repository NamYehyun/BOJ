#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int num_lesson, num_disk;
    cin >> num_lesson >> num_disk;

    long long max_length = 0;
    long long net_length = 0;
    vector<long long> lessons(num_lesson);
    for (int i = 0; i < num_lesson; ++i) {
        cin >> lessons[i];
        max_length = (max_length > lessons[i]) ? max_length : lessons[i];
        net_length += lessons[i];
    }

    int lo = max_length;
    int hi = net_length;
    long long ans = 0;
    while (!(lo > hi)) {
        int mid = (lo + hi) / 2;

        long long acc = 0;
        int req_disk = 1;
        for (int i = 0; i < num_lesson; ++i) {
            if (mid < acc + lessons[i]) {
                ++req_disk;
                acc = lessons[i];
            } else {
                acc += lessons[i];
            }
        }

        if (req_disk <= num_disk) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

