#include <iostream>

using namespace std;


bool kth_term(long long k, long long length) {
    long long mid = length/2 + 1;
    
    if (k == mid) {
        return false;
    }

    return (k < mid) ? kth_term(k, length/2) : !kth_term(2*mid - k, length/2);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int num_test;
    cin >> num_test;
    for (int test = 1; test <= num_test; ++test) {
        cout << "Case #" <<test << ": ";
        
        long long k;
        cin >> k;
        
        long long length = 1;
        while (true) {
            if (k <= length) {
                break;
            }

            length = 2*length + 1;
        }

        cout << kth_term(k, length) << '\n';
    }

    return EXIT_SUCCESS;
}

