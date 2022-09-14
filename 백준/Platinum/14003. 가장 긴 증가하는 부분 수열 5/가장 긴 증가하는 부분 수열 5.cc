#include <iostream>
#include <stack>
#define N 1000005

using namespace std;

int arr[N] = {}, dp[N] = {};
int cnt = 0;
pair < int, int > p[N];
stack < int > st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i == 0) {
            dp[cnt] = arr[i];
            p[i] = make_pair(cnt, arr[i]);
        }
        else if(dp[cnt] < arr[i]) {
            dp[++cnt] = arr[i];
            p[i] = make_pair(cnt, arr[i]);
        }
        else {
            int temp = lower_bound(dp, dp + cnt, arr[i]) - dp;
            dp[temp] = arr[i];
            p[i] = make_pair(temp, arr[i]);
        }
    }
    cout << cnt + 1 << "\n";
    
    for(int i = n - 1; i >= 0; i--) {
        if(p[i].first == cnt) {
            st.push(p[i].second);
            cnt--;
        }
    }
    
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}