#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 10;

bool flag = false;

int n;

bool visit[N] = {};

vector < char > v;
vector < string > ans;

void f_dfs(int num, int cnt, string str) {
    if(cnt == n) ans.push_back(str);
    else {
        for(int i = 0; i < N; i++) {
            if(!visit[i]) {
                if(v[cnt] == '<') {
                    if(num > i) continue;
                }
                else {
                    if(num < i) continue;
                }
                visit[i] = true;
                string st = str + to_string(i);
                f_dfs(i, cnt + 1, st);
            }
        }
    }
    visit[num] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    for(int i = 0; i < N; i++) {
        string str = to_string(i);
        visit[i] = true;
        f_dfs(i, 0, str);
    }
    cout << ans[ans.size() - 1] << "\n";
    cout << ans[0];
    return 0;
}