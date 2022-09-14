#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int Alphabets = 26;

int n, k;
int ans = 0;

bool visit[Alphabets] = {};

vector < string > v;

void f_dfs(int cnt, int alphabet) {
    if(cnt == k) {
        int temp = 0;
        for(int i = 0; i < v.size(); i++) {
            bool flag = true;
            for(int j = 0; j < v[i].size(); j++) {
                if(visit[v[i][j] - 'a'] == false) {
                    flag = false;
                    break;
                }
            }
            if(flag) temp++;
        }
        ans = max(ans, temp);
        return;
    }
    else {
        for(int i = alphabet; i < Alphabets; i++) {
            if(!visit[i]) {
                visit[i] = true;
                f_dfs(cnt + 1, i);
                visit[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        str = str.substr(4, str.size());
        for(int j = 0; j < 4; j++) {
            str.pop_back();
        }
        v.push_back(str);
    }
    if(k < 5) cout << "0";
    else {
        visit['a' - 'a'] = true;
        visit['c' - 'a'] = true;
        visit['n' - 'a'] = true;
        visit['t' - 'a'] = true;
        visit['i' - 'a'] = true;
        k -= 5;
        f_dfs(0, 0);
        cout << ans;
    }
    return 0;
}