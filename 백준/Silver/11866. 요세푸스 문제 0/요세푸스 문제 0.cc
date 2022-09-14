#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue < int > q;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    cout << "<";
    while(!q.empty()) {
        int temp;
        for(int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        temp = q.front();
        cout << temp ;
        if(q.size() != 1) cout << ", ";
        else cout << ">";
        q.pop();
    }
    return 0;
}