#include <iostream>
#include <stack>

using namespace std;

const int N = 1000005;

int arr[N] = {};
int ans[N] = {};

stack < int > st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill_n(ans, N, -1);
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}