/*
 * Let s be a self-representing sequence of length n.
 *
 *   fact 1) sum(s) = len(s) = n
 *   fact 2) s contains (n-s_0) non-zero terms.
 *
 * From the facts, s_1, s_2, ..., s_{n-1} contains ((n-s_0)-1) non-zero terms and their sum is (n-s_0).
 * That is, one term is 2, ((n-s_0)-2) terms are 1s, and the rest are 0s.
 *
 *
 * Case 1: s_0 = 1
 *   s_i = 1  (i = 0)
 *         2  (i = 1 = s_0)
 *         1  (i = 2)
 *         0  (o.w.)
 *
 *   Here, s_1 = ((n-1)-2) + 1 = 2, 
 *         s_2 = 1 + 0 = 1.
 *
 *   The only possible case is n = 4 and s = <1, 2, 1, 0>.
 *
 *
 * Case 2: s_0 = 2
 *   s_i = 2    (i = 0)
 *         n-4  (i = 1)
 *         2    (i = 2 = s_0)
 *         0    (o.w.)
 *
 *   Here, s_1 = ((n-2)-2) + 0 = n-4,
 *         s_2 = 1 + 1 = 2.
 *         
 *   Possible cases are 
 *     n = 4, s = <2, 0, 2, 0>
 *     n = 5, s = <2, 1, 2, 0, 0>
 *
 *
 * Case 3: s_0 >= 3
 *   s_i = s_0        (i = 0)
 *         (n-s_0)-2  (i = 1)
 *         1          (i = 2)
 *         1          (i = s_0)
 *         0          (o.w.)
 *   
 *   Case 3-1: s_0 >= n-3 (and 2 < n-3)
 *     i |   0,   1,   2,   3 ... n-4, n-3, n-2, n-1
 *     s | n-3,   1,   1,   0 ...   0,   1,   0,   0
 *
 *     -> No term is two. (contradiction)
 *
 *   Case 3-2: s_0 = n-4 (and 2 < n-4)
 *     i |   0,   1,   2,   3 ... n-5, n-4, n-3, n-2, n-1
 *     s | n-4,   2,   1,   0 ...   0,   1,   0,   0,   0
 *
 *     -> OK.
 *
 *   Case 3-3: s_0 <= n-5 (and 2 < n-5)
 *     i |   0,   1,   2,   3 ... n-6, n-5, n-4, n-3, n-2, n-1
 *     s | n-5,   3,   1,   0 ...   0,   1,   0,   0,   0,   0
 *
 *     -> Only 2 terms are one. (contradiction)
 *
 *
 *   Therefore, for each n = k > 6, s = <n-4, 2, 1, 0, ..., 0, 1, 0, 0, 0>
 *
 */

#include <iostream>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        switch (n) {
            case 1:
            case 2:
            case 3:
            case 6:
                cout << 0 << '\n';
                break;
            case 4:
                cout << 2 << '\n';
                break;
            case 5:
                cout << 1 << '\n';
                break;
            default:
                cout << 1 << '\n';
                break;
        }
    }
    return EXIT_SUCCESS;
}

