#include <iostream>
#include <queue>

using namespace std;

priority_queue < int > min_pq;
priority_queue < int > max_pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    while(n--) {
        int temp;
        cin >> temp;
        if(min_pq.size() == max_pq.size()) {
            min_pq.push(temp);
        }
        else max_pq.push(-temp);
        if(!min_pq.empty() && !max_pq.empty() && -max_pq.top() < min_pq.top()) {
            int tmin = min_pq.top(), tmax = -max_pq.top();
            max_pq.pop();
            min_pq.pop();
            min_pq.push(tmax);
            max_pq.push(-tmin);
        }
        cout << min_pq.top() << "\n";
    }
    return 0;
}