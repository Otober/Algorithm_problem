#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;

vector < int > v[N];

bool visit[N] = {};
int work[N] = {};

bool f_dfs(int now) {
    if(visit[now]) return false;
    visit[now] = true;
    for(int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if(!work[next] || f_dfs(work[next])) {
            work[next] = now;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    int answer = 0;
    cin >> n >> m >> k;;
    for(int i = 1; i <= n; i++) {
        int t, work;
        cin >> t;
        while(t--) {
            cin >> work;
            v[i].push_back(work);
        }
    }
    for(int i = 1; i <= n; i++) {
        fill_n(visit, n + 1, false);
        if(f_dfs(i)) answer++;
    }
    for(int i = 1; i <= n; i++) {
        fill_n(visit, n + 1, false);
        if(f_dfs(i)) {
            answer++;
            k--;
            if(k == 0) break;
        }
    }
    cout << answer;
    return 0;
}