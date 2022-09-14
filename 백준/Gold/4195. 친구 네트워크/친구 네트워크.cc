#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int N = 2 * 100005;

map < string, int > mp;

int group[N] = {};
int amount[N] = {};

void f_initialize(int n) {
    mp.clear();
    for(int i = 0; i < 2 * n; i++) {
        group[i] = i;
        amount[i] = 1;
    }
}

int f_group(int node) {
    while(group[node] != node) {
        node = group[node];
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; 
    while(t--) {
        int n;
        int cnt = 0;
        cin >> n;
        f_initialize(n);
        for(int i = 0; i < n; i++) {
            int idx[2] = {};
            for(int j = 0; j < 2; j++) {
                string st;
                cin >> st;
                if(mp.find(st) == mp.end()) mp.insert(make_pair(st, cnt++));
                idx[j] = mp[st];
            }
            idx[0] = f_group(idx[0]);
            idx[1] = f_group(idx[1]);
            if(idx[0] > idx[1]) swap(idx[0], idx[1]);
            if(idx[0] != idx[1]) {
                group[idx[1]] = idx[0];
                amount[idx[0]] += amount[idx[1]];
            }
            cout << amount[idx[0]] << "\n";
        }
    }
    return 0;
}