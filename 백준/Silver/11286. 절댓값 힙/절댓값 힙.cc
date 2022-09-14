#include <iostream>
#include <queue>

using namespace std;

priority_queue< pair < int , int > > pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n--) {
        int temp;
        cin >> temp;
        if(temp == 0) {
            if(pq.empty()) cout << "0" << "\n";
            else {
                cout << -pq.top().second << "\n";
                pq.pop();
            }
        }
        else {
            if(temp < 0) pq.push(make_pair(temp, -temp));
            else pq.push(make_pair(-temp, -temp));
        }
    }
    return 0;
}