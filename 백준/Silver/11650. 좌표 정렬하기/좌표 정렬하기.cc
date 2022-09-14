#include <iostream>
#include <algorithm>
#define N 100005

using namespace std;

struct position {
    int x,y;
} ps[N];

bool cmp(const position &a, const position &b) {
    if(a.x < b.x) return true;
    else if(a.x == b.x) {
        if(a.y < b.y) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    sort(ps, ps + n, cmp);
    for(int i = 0; i < n; i++) {
        printf("%d %d\n",ps[i].x, ps[i].y);
    }
    return 0;
}