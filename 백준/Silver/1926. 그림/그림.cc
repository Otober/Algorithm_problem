#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 505;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m;
int cnt = 0;

bool visit[N][N] = {};

int arr[N][N] = {};

vector < int > ans;

bool f_check(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    if(arr[y][x] == 0) return false;
    if(visit[y][x]) return false;
    return true;
}

void f_dfs(int y, int x) {
    cnt++;
    visit[y][x] = true;
    
    for(int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(f_check(ny, nx)) f_dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visit[i][j] && arr[i][j] == 1) {
                cnt = 0;
                f_dfs(i, j);
                ans.push_back(-cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.empty()) cout << "0" << "\n" << "0";
    else cout << ans.size() << "\n" << -ans[0];
    return 0;
}