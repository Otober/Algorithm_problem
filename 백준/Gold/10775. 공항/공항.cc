#include <iostream>
#define N 100005

using namespace std;

int parent[N] = {};

int f_find(int node) {
    if(parent[node] == node) return node;
    return parent[node] = f_find(parent[node]);
}

void f_union(int x, int y) {
    x = f_find(x);
    y = f_find(y);
    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int g, p;
    int cnt = 0;
    
    cin >> g >> p;
    for(int i = 1; i <= g; i++) parent[i] = i;
    while(p--) {
        int temp;
        cin >> temp;
        temp = f_find(temp);
        if(temp == 0) break;
        else {
            cnt++;
            f_union(temp, temp - 1);
        }
    } 
    cout << cnt;
    return 0;
}