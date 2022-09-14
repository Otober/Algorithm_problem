#include <iostream>
#include <climits>
#define N 21

using namespace std;

int arr[N][N] = {};
bool team[N] = {};
int n;
int answer_min = INT_MAX;
void dfs(int cnt, int last) {
    if(cnt == n/2) {
        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(team[i] == team[j] && team[i] == true) t1 +=arr[i][j];
                if(team[i] == team[j] && team[i] == false) t2 +=arr[i][j];
            }
        }
        
        int temp = t1 - t2;
        if(temp < 0) temp = -temp;
        if(temp < answer_min) answer_min = temp;
        return;
    }
    
    for(int i = last + 1; i < n; i++) {
        if(!team[i]) {
            team[i] = true;
            dfs(cnt + 1, i);
            team[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    team[0] = true;
    dfs(1, 0);
    cout << answer_min;
    return 0;
}