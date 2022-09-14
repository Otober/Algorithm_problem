#include <iostream>
#include <string>
#include <queue>
#define N 10000

using namespace std;

bool visit[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        queue < pair < int, string > > q;
        int a, b;
        cin >> a >> b;
        
        fill_n(visit, N, false);
        q.push(make_pair(a, ""));
        visit[a] = true;
        
        while(!q.empty()) {
            int num = q.front().first;
            string str = q.front().second;
            int temp;
            q.pop();
            
            if(num == b) {
                cout << str << endl;
                break;
            }
            temp = (num * 2) % N;
            if(visit[temp] == false) {
                visit[temp] = true;
                q.push(make_pair(temp, str + "D"));
            }
            
            temp = (num - 1 < 0) ? 9999 : num - 1;
            if(visit[temp] == false) {
                visit[temp] = true;
                q.push(make_pair(temp, str + "S"));
            }
            
            temp = (num % 1000) * 10 + (num / 1000);
            if(visit[temp] == false) {
                visit[temp] = true;
                q.push(make_pair(temp, str + "L"));
            }
            
            temp = (num % 10) * 1000 + (num / 10);
            if(visit[temp] == false) {
                visit[temp] = true;
                q.push(make_pair(temp, str + "R"));
            }
        }
    }
    return 0;
}