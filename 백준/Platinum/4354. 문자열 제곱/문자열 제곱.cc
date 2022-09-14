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
    
    while(true) {
        string st;
        getline(cin, st);
        
        if(st == ".") break;
        vector < int > ans = f_getpi(st);
        int len = ans.size();
        if(ans[len - 1] == 0 || ans[len - 1] % (len - ans[len - 1]) != 0) cout << "1" <<"\n";
        else cout << ans[len - 1] / (len - ans[len - 1]) + 1 << "\n";
    }
    return 0;
}