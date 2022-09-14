#include <iostream>
#include <algorithm>
#define N 100005

using namespace std;

typedef long long ll;

ll arr[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll ans = 0;
    int temp = 0;
    int ans_num = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    ans = arr[0];
    temp++;
    ans_num++;
    
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) temp++;
        else temp = 1;
        if(ans_num < temp) {
            ans_num = temp;
            ans = arr[i];
        }
    }
    cout << ans;
    return 0;
}