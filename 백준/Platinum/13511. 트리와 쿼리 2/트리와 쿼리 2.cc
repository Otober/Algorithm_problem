#include <iostream>
#include <vector>
#include <algorithm>
#define N 100005
#define LOGN 18

using namespace std;
typedef long long ll;

int n;
int depth[N] = {};
int arr[N][LOGN] = {};
ll dist[N] = {};

vector < pair < int, int > > v[N];

void f_tree(int node, int parent, int cost) {
    depth[node] = depth[parent] + 1;
    arr[node][0] = parent;
    for(int i = 0; i < v[node].size(); i++) {
        int next = v[node][i].first;
        int ncost = v[node][i].second;
        if(next != parent) {
            dist[next] = dist[node] + ncost;
            f_tree(next, node, ncost);
        }
    }
}

void f_func() {
    for(int i = 1; i < LOGN; i++) {
        for(int node = 1; node <= n; node++) {
            int temp = arr[node][i - 1];
            arr[node][i] = arr[temp][i - 1];
        }
    }
}

int f_lca(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b);
    for(int i = LOGN - 1; i >= 0; i--) {
        if(depth[a] <= depth[arr[b][i]]) b = arr[b][i];
    }
    
    int ans = a;
    if(a != b) {
        for(int i = LOGN - 1; i >= 0; i--) {
            if(arr[a][i] != arr[b][i]) {
                a = arr[a][i];
                b = arr[b][i];
            }
            ans = arr[a][i];
        }
    }
    return ans;
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
    f_func();
    
    int m;
    cin >> m;
    while(m--) {
        int q;
        cin >> q;
        if(q == 1) {
            int a, b, p;
            cin >> a >> b;
            p = f_lca(a, b);
            cout << dist[a] + dist[b] - 2 * dist[p] << "\n";
        }
        else {
            int a, b, c, p;
            int cnt = 0;
            cin >> a >> b >> c;
            p = f_lca(a, b);
            if(c > depth[a] - depth[p] + 1) {
                c -= depth[a] - depth[p] + 1;
                c = depth[b] - depth[p] - c;
                while(c) {
                    if(c % 2) b = arr[b][cnt];
                    c /= 2;
                    cnt++;
                }
                cout << b << "\n";
            }
            else {
                c--;
                while(c) {
                    if(c % 2) a = arr[a][cnt];
                    c /= 2;
                    cnt++;
                }
                cout << a << "\n";
            }
        }
    }
    return 0;
}