#include <iostream>
#define N 1030

using namespace std;

typedef long long ll;

int n, m;
ll arr[N][N] = {};
ll tree[N][N] = {};

void f_update(int y, int x, int val) {
    int r = y;
    while(r <= n) {
        int c = x;
        while(c <= n) {
            tree[r][c] += val;
            c += (c & -c);
        }
        r += (r & -r);
    }
}

ll f_sum(int y, int x) {
    int ans = 0;
    int r = y;
    while(r > 0) {
        int c = x;
        while(c > 0) {
            ans += tree[r][c];
            c -= (c & -c);
        }
        r -= (r & -r);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            f_update(i, j, arr[i][j]);
        }
    }
    
    while(m--) {
        int way;
        cin >> way;
        if(way == 0) {
            int y, x;
            ll val;
            cin >> y >> x >> val;
            ll diff = val - arr[y][x];
            arr[y][x] = val;
            f_update(y, x, diff);
        }
        if(way == 1) {
            int x1, x2, y1, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << f_sum(y2, x2) - f_sum(y1 -1, x2) - f_sum(y2, x1 - 1) + f_sum(y1 - 1, x1 - 1) << "\n";
        }
    }
    return 0;
}