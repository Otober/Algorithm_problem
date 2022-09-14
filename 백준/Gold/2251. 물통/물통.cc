#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 205;

struct Capacity {
    int a, b, c;
    Capacity(int _a, int _b, int _c)
        :a(_a), b(_b), c(_c)
    {}
};

bool ans[N] = {};

bool visit[N][N] = {};

queue < Capacity > q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    q.push({0, 0, c});
    while(!q.empty()) {
        Capacity now = q.front();
        q.pop();
        
        if(visit[now.a][now.b]) continue;
        visit[now.a][now.b] = true;
        
        if(now.a == 0) ans[now.c] = true;
        
        // a -> b
        if(now.a + now.b > b) q.push({now.a + now.b - b, b, now.c});
        else q.push({0, now.a + now.b, now.c});
        
        // a -> c
        if(now.a + now.c > c) q.push({now.a + now.b - c, now.b, c});
        else q.push({0, now.b, now.a + now.c});
        
        // b -> a
        if(now.a + now.b > a) q.push({a, now.a + now.b - a, now.c});
        else q.push({now.a + now.b, 0, now.c});
        
        // b -> c
        if(now.b + now.c > c) q.push({now.a, now.b + now.c - c, c});
        else q.push({now.a, 0, now.b + now.c});
        
        // c -> a
        if(now.a + now.c > a) q.push({a, now.b, now.a + now.c - a});
        else q.push({now.a + now.c, now.b, 0});
        
        // c -> b
        if(now.b + now.c > b) q.push({now.a, b, now.b + now.c - b});
        else q.push({now.a, now.b + now.c, 0});
    }
    for(int i = 0; i < N; i++) {
        if(ans[i]) cout << i << " ";
    }
    return 0;
}