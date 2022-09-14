#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 105;

bool visit[N][N] = {};

int cnt = 0;
int n, m;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool f_check(int y, int x) {
    if(y < 0 || y >= m) return false;
    if(x < 0 || x >= n) return false;
    if(visit[y][x]) return false;
    return true;
}

void f_dfs(int y, int x) {
    visit[y][x] = true;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(f_check(ny, nx)) f_dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    vector < int > v;
    cin >> m >> n >> k;
    while(k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i = b; i < d; i++) {
            for(int j = a; j < c; j++) {
                visit[i][j] = true;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j] == false) {
                cnt = 0;
                f_dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(vector < int >::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}