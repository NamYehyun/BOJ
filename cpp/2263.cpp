#include <iostream>
#include <map>
#include <vector>

using namespace std;


void solve(vector<int>& inorder, int in_start, int in_end,
           vector<int>& postorder, int post_start, int post_end, 
           map<int, int>& index, vector<int>& preorder) {

    if (in_end < in_start || post_end < post_start) {
        return;
    }

    int root = postorder[post_end];
    int root_idx = index[root];

    preorder.push_back(root);

    solve(inorder, in_start, root_idx-1,
          postorder, post_start, post_start+root_idx-in_start-1,
          index, preorder);

    solve(inorder, root_idx+1, in_end,
          postorder, post_start+root_idx-in_start, post_end-1, 
          index, preorder);

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> inorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    vector<int> postorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    map<int, int> index;
    for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
    }

    vector<int> preorder;
    solve(inorder, 0, n-1, postorder, 0, n-1, index, preorder);

    for (int i = 0; i < n; ++i) {
        cout << preorder[i] << ' ';
    }
    cout << '\n';

    return EXIT_SUCCESS;
}

