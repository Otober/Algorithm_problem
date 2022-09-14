#include <iostream>
#include <vector>
#include <algorithm>
#define N 100005
#define LOGN 18
#define INF 987654321

using namespace std;

int n;
int depth[N] = {};
int arr[N][LOGN] = {};
int max_dp[N][LOGN] = {};
int min_dp[N][LOGN] = {};

vector < pair < int, int > > v[N];

void f_tree(int node, int parent, int cost) {
    depth[node] = depth[parent] + 1;
    arr[node][0] = parent;
    max_dp[node][0] = cost;
    min_dp[node][0] = cost;
    
    for(int i = 1; i < LOGN; i++) {
        int temp = arr[node][i - 1];
        arr[node][i] = arr[temp][i - 1];
    }
    
    for(int i = 0; i < v[node].size(); i++) {
        int next = v[node][i].first;
        int ncost = v[node][i].second;
        if(next != parent) f_tree(next, node, ncost);
    }
}

void f_dp() {
    for(int i = 1; i < LOGN; i++) {
        for(int node = 1; node <= n; node++) {
            int temp = arr[node][i - 1];
            min_dp[node][i] = min(min_dp[node][i - 1], min_dp[temp][i - 1]);
            max_dp[node][i] = max(max_dp[node][i - 1], max_dp[temp][i - 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    
    depth[0] = -1;
    f_tree(1, 0, 0);
    f_dp();
    
    int k;
    cin >> k;
    while(k--) {
        int a, b;
        int ans_min = INF;
        int ans_max = -INF;
        
        cin >> a >> b;
        if(depth[a] > depth[b]) swap(a, b);
        for(int i = LOGN - 1; i >= 0; i--) {
            if(depth[a] <= depth[arr[b][i]]) {
                ans_min = min(ans_min, min_dp[b][i]);
                ans_max = max(ans_max, max_dp[b][i]);
                b = arr[b][i];
            }
        }
        
        int lca = a;
        if(a != b) {
            for(int i = LOGN - 1; i >= 0; i--) {
                if(arr[a][i] != arr[b][i]) {
                    ans_min = min(ans_min, min(min_dp[a][i], min_dp[b][i]));
                    ans_max = max(ans_max, max(max_dp[a][i], max_dp[b][i]));
                    a = arr[a][i];
                    b = arr[b][i];
                }
                lca = arr[a][i];
            }
        }
        if(a != lca) {
            ans_min = min(ans_min, min(min_dp[a][0], min_dp[b][0]));
            ans_max = max(ans_max, max(max_dp[a][0], max_dp[b][0]));
        } 
        cout << ans_min << " " << ans_max << "\n";
    }
    return 0;
}