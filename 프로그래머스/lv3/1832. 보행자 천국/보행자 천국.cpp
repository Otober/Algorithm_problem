#include <vector>

using namespace std;

const int N = 505;
const int MOD = 20170805;

int r[N][N] = {};
int d[N][N] = {};

void f_initialize() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            r[i][j] = 0;
            d[i][j] = 0;
        }
    }
    r[1][1] = 1;
    d[1][1] = 1;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    f_initialize();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(city_map[i][j] == 0) {
                r[i + 1][j + 1] = (r[i + 1][j + 1] + r[i + 1][j] + d[i][j + 1]) % MOD;
                d[i + 1][j + 1] = (d[i + 1][j + 1] + r[i  + 1][j] + d[i][j + 1]) % MOD;
            }
            else if(city_map[i][j] == 1) {
                r[i + 1][j + 1] = 0;
                d[i + 1][j + 1] = 0;
            }
            else {
                r[i + 1][j + 1] = r[i + 1][j];
                d[i + 1][j + 1] = d[i][j + 1];
            }
        }
    }
    return answer = r[m][n];
}