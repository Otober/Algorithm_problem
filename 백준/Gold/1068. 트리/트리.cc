#include <iostream>
#include <vector>

using namespace std;

const int N = 55;

bool flag = false;

int n, del;
int ans = 0;

bool visit[N] = {};

int arr[N] = {};
int child[N] = {};

void f_dfs(int node) {
    if(node == del) {
        flag = true;
        visit[node] = true;
        return;
    }
    if(arr[node] == -1) return;
    f_dfs(arr[node]);
    if(flag) visit[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] != -1) child[arr[i]]++;
    }
    cin >> del;

    for(int i = 0; i < n; i++) {
        flag = false;
        f_dfs(i);
    }
    for(int i = 0; i < n; i++) {
        if(visit[i]) {
            if(arr[i] != -1) child[arr[i]]--;
        }
    }
    for(int i = 0; i < n; i++) {
        if(child[i] == 0 && !visit[i]) ans++;
    }
    cout << ans;
    return 0;
}