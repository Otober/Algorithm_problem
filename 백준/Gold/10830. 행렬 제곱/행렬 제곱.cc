#include <iostream>
#include <vector>
#define N 8
#define devive 1000

using namespace std;

int n;
long long b;
int arr[N][N] = {};

vector < vector < int > > f_calculate(vector < vector < int > > a, vector < vector < int > > b) {
    vector < vector < int > > temp(n, vector < int > (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= devive;
        }
    }
    return temp;
}

vector < vector < int > > f_calculate(vector < vector < int > > a, int b[N][N]) {
    vector < vector < int > > temp(n, vector < int > (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = b[i][j];
        }
    }
    return f_calculate(a, temp);
}

vector < vector < int > > f_solve(long long sq) {
    vector < vector < int > > ans(n, vector < int >(n));
    vector < vector < int > > temp(n, vector < int >(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) ans[i][j] = 1;
            else ans[i][j] = 0;
        }
    }
    
    if(sq == 1) {
        ans = f_calculate(ans, arr);
    }
    else if(sq % 2) {
        temp = f_solve(sq - 1);
        ans = f_calculate(temp, arr);
    }
    else {
        temp = f_solve(sq / 2);
        ans = f_calculate(temp, temp);
    }
    return ans;
}

void f_print(vector < vector < int > > ans) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j ++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> b;
    vector < vector < int > > ans(n, vector < int > (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    f_print(f_solve(b));
    return 0;
}