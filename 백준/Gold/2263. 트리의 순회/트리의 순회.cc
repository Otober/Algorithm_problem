#include <iostream>
#define N 100005

using namespace std;

int inorder[N] = {};
int postorder[N] = {};

void f_traversal(int in_s, int in_e, int post_s, int post_e) {
    if(in_s > in_e || post_s > post_e) return;
    int root = postorder[post_e];
    cout << root << " ";
    f_traversal(in_s, inorder[root] - 1, post_s, post_s + (inorder[root] - in_s) - 1);
    f_traversal(inorder[root] + 1, in_e, post_s + (inorder[root] - in_s), post_e - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        inorder[temp] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    f_traversal(0, n - 1, 0, n - 1);
    return 0;
}