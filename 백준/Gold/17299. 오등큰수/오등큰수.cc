#include <iostream>
#include <stack>

using namespace std;

const int N = 1000005;

int arr[N] = {};
int visit[N] = {};
int result[N] = {};

stack < pair < int, int > > st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        visit[arr[i]]++;
    }
    
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && visit[arr[i]] >= st.top().first) {
            st.pop();
        }
        
        result[i] = st.empty() ? -1 : st.top().second;
        st.push(make_pair(visit[arr[i]], arr[i]));
    }
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}