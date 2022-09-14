#include <iostream>
#include <vector>
#define N 9

using namespace std;

int arr[N][N] = {};
vector < pair <int, int> > adj;

bool check(int y, int x, int temp) {
    for(int i = 0; i < N; i++) {
        if(arr[y][i] == temp) return false;
        if(arr[i][x] == temp) return false;
    }
    for(int i = (y / 3)  * 3; i < (y / 3) * 3 + 3; i++) {
        for(int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
            if(arr[i][j] == temp) return false;
        }
    }
    return true;
}

void dfs(int cnt) {
    if(cnt == adj.size()) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    
    for(int i = 1; i <= N; i++) {
        int y = adj[cnt].first;
        int x = adj[cnt].second;
        if(check(y, x, i)) {
            arr[y][x] = i;
            dfs(cnt + 1);
            arr[y][x] = 0;
        }
    }
}

int main() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) {
                adj.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0);
    return 0;
}