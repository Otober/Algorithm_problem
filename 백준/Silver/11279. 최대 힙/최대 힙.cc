#include <iostream>
#include <queue>

using namespace std;

priority_queue < int > pq;

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
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(temp);
    }
    return 0;
}