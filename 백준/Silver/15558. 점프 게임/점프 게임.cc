#include <iostream>
#include <queue>

using namespace std;

const int N = 100005;

bool flag = false;

int n, k;
int maginot = 0;

bool visit[2 * N][2] = {};

char arr[2 * N][2] = {};

queue < pair < int, int > > q;

bool f_check(int next, int line) {
    if(next < 0) return false;
    if(next <= maginot) return false;
    if(arr[next][line] == '0') return false;
    if(visit[next][line]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0; i < 2 * N; i++) {
        fill_n(arr[i], 2, '1');
        fill_n(visit[i], 2, false);
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[j][i];
        }
    }
    
    visit[0][0] = true;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        int t = q.size();
        while(t--) {
            int now = q.front().first;
            int line = q.front().second;
            q.pop();
            
            if(now >= n) {
                flag = true;
                break;
            }
            if(f_check(now + 1, line)) {
                visit[now + 1][line] = true;
                q.push(make_pair(now + 1, line));
            }
            if(f_check(now - 1, line)) {
                visit[now - 1][line] = true;
                q.push(make_pair(now - 1, line));
            }
            if(f_check(now + k, (line + 1) % 2)) {
                visit[now + k][(line + 1) % 2] = true;
                q.push(make_pair(now + k, (line + 1) % 2));
            }
        }
        if(flag) break;
        else maginot++;
    }
    if(flag) cout << '1';
    else cout << "0";
    return 0;
}