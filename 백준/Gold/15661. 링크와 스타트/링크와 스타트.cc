#include <iostream>
#include <cmath>

using namespace std;

const int N = 25;
const int INF = 987654321;

int ans = INF;

int arr[N][N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int k = 1; k < ((1 << n) - 1); k++) {
        int link = 0;
        int start = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(((k & (1 << i)) == 0) && ((k & (1 << j)) == 0)) link += (arr[i][j] + arr[j][i]);
                else if(((k & (1 << i)) != 0) && ((k & (1 << j)) != 0)) start += (arr[i][j] + arr[j][i]);
            }
        }
        ans = min(ans, abs(link - start));
    }
    cout << ans;
    return 0;
}