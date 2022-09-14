#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        int cnt = 0;
        queue < pair < int, int > >q;
        priority_queue < int > pq;
        
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            q.push(make_pair(i, temp));
            pq.push(temp);
        }
        
        while(!q.empty()) {
            int document = q.front().first;
            int importance = q.front().second;
            q.pop();
            if(pq.top() == importance) {
                cnt++;
                pq.pop();
                if(document == m) {
                    cout << cnt << endl;
                    break;
                }
            }
            else q.push(make_pair(document, importance));
        }
    }
    return 0;
}