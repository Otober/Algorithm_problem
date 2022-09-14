#include <iostream>

using namespace std;

const int N = 1005;
const int M = 8;

int visit[N] = {};

char gear[N][M] = {};

void f_rotate(int n) {
    if(visit[n] == 1) {
        char temp = gear[n][M - 1];
        for(int i = M - 2; i >= 0; i--) {
            gear[n][i + 1] = gear[n][i];
        }
        gear[n][0] = temp;
    }
    else {
        char temp = gear[n][0];
        for(int i = 1; i < M; i++) {
            gear[n][i - 1] = gear[n][i];
        }
        gear[n][M - 1] = temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < M; j++) {
            cin >> gear[i][j];
        }
    }
    
    int k;
    cin >> k;
    while(k--) {
        fill_n(visit, N, 0);
        int num, dir;
        cin >> num >> dir;
        num--;
        visit[num] = dir;
        
        int n_num = num + 1;
        while(n_num < t) {
            if(gear[n_num - 1][2] != gear[n_num][6]) {
                visit[n_num] = -visit[n_num - 1];
                n_num++;
            }
            else break;
        }
        
        n_num = num - 1;
        while(n_num >= 0) {
            if(gear[n_num + 1][6] != gear[n_num][2]) {
                visit[n_num] = -visit[n_num + 1];
                n_num--;
            }
            else break;
        }
        
        for(int i = 0; i < t; i++) {
            if(visit[i] != 0) f_rotate(i);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < t; i++) {
        ans += (int)(gear[i][0] - '0');
    }
    cout << ans;
    return 0;
}