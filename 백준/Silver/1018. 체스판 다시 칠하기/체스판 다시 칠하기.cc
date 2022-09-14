#include <iostream>
#define N 55

using namespace std;

bool arr[N][N] = {};

int f_min(int a,int b) {
    return a < b ? a : b;
}

int main() {
    int n,m;
    int cnt_min = 987654321;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if(temp == 'W') arr[i][j] = false;
            else arr[i][j] = true;
        }
    }
    
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            int cnt = 0;
            
            for(int y = i; y < i + 8; y++) {
                for(int x = j; x < j + 8; x++) {
                    if((y % 2) ^ (x % 2)) {
                        if(arr[y][x] == true) cnt++;
                    }
                    else {
                        if(arr[y][x] == false) cnt++;
                    }
                }
            }
            
            cnt_min = f_min(cnt_min, cnt);
            cnt_min = f_min(cnt_min, 64 - cnt);
        }
    }
    
    cout << cnt_min << endl;
    return 0;
}