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

void f_print(int i, int j) {
    while(dp[i][j] != 0) {
        if(dp[i][j] == dp[i][j - 1]) j--;
        else if(dp[i][j] == dp[i - 1][j]) i--;
        else if(dp[i][j] - 1 == dp[i - 1][j - 1]) {
            f_print(i - 1, j - 1);
            cout << str1[i - 1];
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str1;
    cin >> str2;
    
    for(int i = 1; i <= str1.length(); i++) {
        for(int j = 1; j <= str2.length(); j++) {
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = f_max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[str1.length()][str2.length()] << endl;
    f_print(str1.length(), str2.length());
    return 0;
}