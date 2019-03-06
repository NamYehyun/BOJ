#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long a, b, v;
    cin >> a >> b >> v;

    cout << (v-b)/(a-b) + static_cast<long long>((v-b)%(a-b) != 0) << endl;
    
    return EXIT_SUCCESS;
}

