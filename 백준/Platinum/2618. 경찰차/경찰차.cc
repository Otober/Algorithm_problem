#include <iostream>
#include <algorithm>
#define N 1005
#define INF 987654321

using namespace std;

int n, w;
int back[N] = {};
int dp[N][N] = {};

pair < int, int > arr[N];

int f_dist(pair < int, int > a, pair < int, int > b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int f_func(int x, int y) {
    if(x == w || y == w) return 0;
    int &ret = dp[x][y];
    
    if(ret != - 1) return ret;
    int first, second;
    if(x) first = f_func(max(x, y) + 1, y) + f_dist(arr[max(x, y) + 1], arr[x]);
    else first = f_func(max(x, y) + 1, y) + f_dist(arr[max(x, y) + 1], {1, 1});
    if(y) second = f_func(x, max(x, y) + 1) + f_dist(arr[max(x, y) + 1], arr[y]);
    else second = f_func(x, max(x, y) + 1) + f_dist(arr[max(x, y) + 1], {n, n});

    return ret = min(first, second);
}

void f_back(int x, int y) {
    if(x == w || y == w) return;
    
    int first, second;
    if(x) first = f_func(max(x, y) + 1, y) + f_dist(arr[max(x, y) + 1], arr[x]);
    else first = f_func(max(x, y) + 1, y) + f_dist(arr[max(x, y) + 1], {1, 1});
    if(y) second = f_func(x, max(x, y) + 1) + f_dist(arr[max(x, y) + 1], arr[y]);
    else second = f_func(x, max(x, y) + 1) + f_dist(arr[max(x, y) + 1], {n, n});
    
    if(first < second) {
        back[max(x, y) + 1] = 1;
        f_back(max(x, y) + 1, y);
    }
    else {
        back[max(x, y) + 1] = 2;
        f_back(x, max(x, y) + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < N; i++) {
        fill_n(dp[i], N, -1);
    }
    
    cin >> n >> w;
    for(int i = 1; i <= w; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << f_func(0, 0) << "\n";
    f_back(0, 0);
    for(int i = 1; i <= w; i++) {
        cout << back[i] << "\n";
    }
    return 0;
}