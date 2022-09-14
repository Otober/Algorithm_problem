#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;

vector < int > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    int mid = n / 2;
    
    vector < int > first(1 << (n - mid));
    for(int i = 0; i < (1 << (n - mid)); i++) {
        for(int j = 0; j < n - mid; j++) {
            if(i & (1 << j)) first[i] += v[j];
        }
    }
    
    vector < int > second(1 << mid);
    for(int i = 0; i < (1 << mid); i++) {
        for(int j = 0; j < mid; j++) {
            if(i & (1 << j)) second[i] += v[j + (n - mid)];
        }
    }
    
    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), greater<int>());
    
    int idx1 = 0, idx2 = 0;
    long long ans = 0;
    
    while(idx1 < (1 << (n - mid)) && idx2 < (1 << mid)) {
        if(first[idx1] + second[idx2] == s) {
            long long cnt1 = 1, cnt2 = 1;
            idx1++; idx2++;
            while(idx1 < (1 << (n - mid)) && first[idx1] == first[idx1- 1]) {
                idx1++;
                cnt1++;
            }
            
            while(idx2 < (1 << mid) && second[idx2] == second[idx2 - 1]) {
                idx2++;
                cnt2++;
            }
            ans += cnt1 * cnt2;
        }
        else if(first[idx1] + second[idx2] < s) idx1++;
        else if(first[idx1] + second[idx2] > s) idx2++;
    }
    
    if(s == 0) ans--;
    cout << ans;
    return 0;
}