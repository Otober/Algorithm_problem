#include <iostream>
#include <string>
#define N 1005

using namespace std;

string str1;
string str2;
int dp[N][N] = {};

int f_max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str1;
    cin >> str2;
    
    for(int i = 0; i < str1.length(); i++) {
        for(int j = 0; j < str2.length(); j++) {
            if(str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = f_max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[str1.length()][str2.length()] << endl;
    return 0;
}