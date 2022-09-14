#include <iostream>
#include <vector>
#define N 500005

using namespace std;

typedef long long ll;

ll ans = 0;

void f_merge(vector < int > &v, int start, int end) {
    if(start == end) return;
    
    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;
    vector < int > temp;
    
    f_merge(v, start, mid);
    f_merge(v, mid + 1, end);
    
    while(left <= mid && right <= end) {
        if(v[left] <= v[right]) temp.push_back(v[left++]);
        else {
            temp.push_back(v[right++]);
            ans += mid + 1 - left;
        }
    }
    while(left <= mid) {
        temp.push_back(v[left++]);
    }
    while(right <= end) {
        temp.push_back(v[right++]);
    }
    for(int i = start, j = 0; i <= end; i++, j++) {
        v[i] = temp[j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector < int > v;
    
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    f_merge(v, 0, n - 1);
    cout << ans;
    return 0;
}