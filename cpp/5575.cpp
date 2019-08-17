#include <iostream>

using namespace std;


inline long long time_to_sec(int h, int m, int s) {
    return 60*60*h + 60*m + s;
}


inline void sec_to_time(long long sec) {
    long long h = sec / (60 * 60);
    long long m = (sec % (60 * 60)) / 60;
    long long s = sec % 60;

    cout << h << ' ' << m << ' ' << s << endl;

    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for (int i = 0; i < 3; ++i) {
        int h1, m1, s1;
        cin >> h1 >> m1 >> s1;

        int h2, m2, s2;
        cin >> h2 >> m2 >> s2;

        sec_to_time(time_to_sec(h2, m2, s2) - time_to_sec(h1, m1, s1));
    }

    return EXIT_SUCCESS;
}

