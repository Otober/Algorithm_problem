#include <iostream>
#include <vector>
#define N 1000005

using namespace std;

vector < int > v;
bool visit[N] = {};

void f_Eratos() {
    for(int i = 2; i <= N; i++) {
        for(int j = 2; j * i <= N; j++) {
            if(visit[i * j] == true) continue;
            visit[i * j] = true;
        }
    }
    for(int i = 3; i <= N; i++) {
        if(visit[i] == false) v.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    f_Eratos();
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < v.size(); i++) {
            if(visit[n - v[i]] == false) {
                cout << n << " = " << v[i] << " + " << n - v[i] << "\n";
                break;
            }
        }
    }
    return 0;
}