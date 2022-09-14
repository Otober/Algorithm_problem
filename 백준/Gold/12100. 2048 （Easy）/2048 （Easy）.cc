#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 23;

int n;

int board[N][N] = {};

int f_dfs(int cnt) {
    if(cnt == 5) {
        int ret = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ret = max(ret, board[i][j]);
            }
        }
        return ret;
    }
    int ret = 0;
    for(int k = 0; k < 4; k++) {
        int temp[N][N];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            vector < int > v;
            for(int j = 0; j < n; j++) {
                if(((k % 2) == 0 ? board[i][j] : board[j][i]) != 0) v.push_back((k % 2) == 0 ? board[i][j] : board[j][i]);
            }
            if(k < 2) reverse(v.begin(), v.end());
            vector < int > next;
            for(int j = 0; j < v.size(); j++) {
                if(j + 1 < v.size() && v[j] == v[j + 1]) {
                    next.push_back(v[j] * 2);
                    j++;
                }
                else next.push_back(v[j]);
            }
            for(int j = next.size(); j < n; j++) {
                next.push_back(0);
            }
            if(k < 2) reverse(next.begin(), next.end());
            for(int j = 0; j < n; j++) {
                ((k % 2) == 0 ? board[i][j] : board[j][i]) = next[j];
            }
        }
        ret = max(ret, f_dfs(cnt + 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = temp[i][j];
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cout << f_dfs(0);
    return 0;
}