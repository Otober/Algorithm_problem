#include <iostream>
#include <string>
#include <vector>

using namespace std;

string p, t;

vector < int > f_pi() {
    vector < int > pi((int)p.size(), 0);
    int m = (int)p.size();
    int j = 0;
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if(p[i] == p[j])  pi[i] = ++j;
    }
    return pi;
}

vector < int > f_kmp() {
    vector < int > ans;
    vector < int > pi = f_pi();
    int j = 0;
    int n = (int)t.size();
    int m = (int)p.size();
    
    for(int i = 0; i < n; i++) {
        while(j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }
        if(t[i] == p[j]) {
            if(j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else j++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin, t);
    getline(cin, p);
    vector < int > match = f_kmp();
    cout << (int)match.size() << "\n";
    for(vector < int > :: iterator iter = match.begin(); iter != match.end(); iter++) {
        cout << *iter + 1<< " ";
    }
    return 0;
}