#include <iostream>
#include <vector>
#include <string>
#define N 16

using namespace std;

vector < string > arr(N);
vector < int > modulo(N);
vector < int > len(N);
vector < int > ten(51);
int n, k;
long long dp[1 << N][105] = {};

long long gcd(long long a,long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        len[i] = arr[i].size();
    }
    cin >> k;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            modulo[i] = modulo[i] * 10 + (arr[i][j] - '0');
            modulo[i] %= k;
        }
    }
    
    ten[0] = 1;
    for(int i = 1; i <= 50; i++) {
        ten[i] = ten[i - 1] * 10;
        ten[i] %= k;
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < k; j++) {
            for(int l = 0; l < n; l++) {
                if((i & (1 << l)) == 0) {
                    int next = j * ten[len[l]];
                    next %= k;
                    next += modulo[l];
                    next %= k;
                    dp[i | (1 << l)][next] += dp[i][j];
                }
            }
        }
    }
    
    long long t1 = dp[(1 << n) - 1][0];
    long long t2 = 1;
    for(int i = 1; i <= n; i++) {
        t2 *= i;
    }
    long long t = gcd(t1, t2);
    cout << t1 / t << "/" << t2 / t << "\n";
    return 0;
}