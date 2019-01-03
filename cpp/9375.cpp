#include <iostream>
#include <map>

using namespace std;


int main(void) {
    int t;
    scanf("%d", &t);

    for (int _ = 0; _ < t; ++_) {
        int n;
        scanf("%d", &n);

        map<string, int> count;
        for (int i = 0; i < n; ++i) {
            string name, type;
            cin >> name >> type;

            if (count.find(type) == count.end()) {
                count[type] = 1;
            } else {
                count[type] += 1;
            }
        }

        long long ans = 1;
        map<string, int>::iterator iter;
        for (iter = count.begin(); iter != count.end(); ++iter) {
            ans *= (iter->second + 1);
        }

        printf("%lld\n", ans - 1);
    }
    
    return EXIT_SUCCESS;
}

