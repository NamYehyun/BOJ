#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, w, h;
    cin >> n >> w >> h;
    
    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;

        cout << (len*len <= w*w + h*h ? "DA" : "NE") << '\n';
    }

    return EXIT_SUCCESS;
}

