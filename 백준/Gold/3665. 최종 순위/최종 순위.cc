#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define N 505

using namespace std;

int n, m;
int arr[N][N] = {};
int ranking[N] = {};
int inDegree[N] = {};

bool flag;

queue < int > q;
vector < int > ans;

void f_initialize(int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            arr[i][j] = 0;
        }
        ranking[i] = 0;
        inDegree[i] = 0;
    }
    flag = true;
    while(!q.empty()) q.pop();
    ans.clear();
}

void f_swap(int &a, int &b) {
    arr[a][b] = 0;
    arr[b][a] = 1;
    inDegree[a]++;
    inDegree[b]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        f_initialize(n);
        
        for(int i = 1; i <= n; i++) {
            cin >> ranking[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                arr[ranking[i]][ranking[j]] = 1;
                inDegree[ranking[j]]++;
            }
        }
        
        cin >> m;
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if(arr[a][b] == 1) f_swap(a, b);
            else f_swap(b, a);
        }
        for(int i = 1; i <= n; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            if(q.size() > 1) {
                flag = false;
                break;
            }
            int next = q.front();
            q.pop();
            ans.push_back(next);
            
            for(int i = 1; i <= n; i++) {
                if(arr[next][i] == 1) {
                    inDegree[i]--;
                    if(inDegree[i] == 0) q.push(i);
                }
            }
        }
        if(flag == false) cout << "?";
        else if(ans.size() == n) {
            for(int i : ans) {
                cout << i << " ";
            }
        }
        else cout << "IMPOSSIBLE";
        cout << "\n";
    }
    return 0;
}