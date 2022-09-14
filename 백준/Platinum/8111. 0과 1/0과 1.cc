#include <iostream>
#include <queue>

using namespace std;

const int N = 20005;

int n;

bool visit[N] = {};

pair < int, char > arr[N];

queue < int > q;

void f_initialize() {
    fill_n(visit, N, false);
    while(!q.empty()) {
        q.pop();
    }
}

void f_bfs() {
    q.push(1);
    visit[1] = true;
    arr[1].first = -1;
    arr[1].second = '1';
    
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        
        int p[2];
        p[0] = (num * 10) % n;
        p[1] = (num * 10 + 1) % n;
        for(int i = 0; i < 2; i++) {
            if(!visit[p[i]]) {
                arr[p[i]].first = num;
                arr[p[i]].second = i + '0';
                if(!p[i]) return;
                visit[p[i]] = true;
                q.push(p[i]);
            }
        }
    }
}

void f_print(int num) {
    if(num == -1) return;
    f_print(arr[num].first);
    cout << arr[num].second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 1) cout << '1' << "\n";
        else {
            f_initialize();
            f_bfs();
            f_print(0);
            cout << "\n";
        }
    }
    return 0;
}