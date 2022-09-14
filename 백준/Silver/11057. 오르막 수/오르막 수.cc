#include <iostream>
#define N 1005
#define devive 10007

using namespace std;

int arr[N][10] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int sum = 0;
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == 1 || j == 0) arr[i][j] = 1;
            else arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % devive;
        }
    }
    
    for(int i = 0; i < 10; i++) {
        sum += arr[n][i];
        sum %= devive;
    }
    cout << sum;
    return 0;
}