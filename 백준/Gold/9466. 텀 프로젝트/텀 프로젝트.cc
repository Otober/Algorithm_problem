#include <iostream>

using namespace std;

int n, cnt;

const int N = 100005;

int arr[N];

bool visit[N], cycle[N];

void f_initialize() {
    cnt = 0;
    fill_n(arr, N, 0);
    fill_n(visit, N, false);
    fill_n(cycle, N, false);
}

void f_dfs(int node) {
    visit[node] = true;
    int next = arr[node];
    
    if(!visit[next]) f_dfs(next);
    else {
        if(!cycle[next]) {
            for(int iter = next; iter != node; iter = arr[iter]) {
                cnt++;
            }
            cnt++;
        }
    }
    cycle[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        f_initialize();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for(int i = 1; i <= n; i++) {
            if(!visit[i]) f_dfs(i);
        }
        cout << n - cnt << "\n";
    }
    return 0;
}