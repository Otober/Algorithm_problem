#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector < int > f_getpi(string p) {
    int m = p.size();
    int j = 0;
    
    vector < int > pi(m, 0);
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if(p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string st;
    cin >> n >> st;
    
    vector < int > ans = f_getpi(st);
    cout << n - ans[n - 1];
    return 0;
}