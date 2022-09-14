#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector < int > v;

bool f_binary_search(int target) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(v[mid] == target) return true;
        else if(v[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if(f_binary_search(temp)) cout << "1" << " ";
        else cout << "0" << " ";
    }
    return 0;
}