#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    queue < int > q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str.compare("push") == 0) {
            int temp;
            cin >> temp;
            q.push(temp);
        }
        
        else if(str.compare("pop") == 0) {
            if(q.empty()) cout << "-1" << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        
        else if(str.compare("size") == 0) {
            cout << q.size() << "\n";
        }
        
        else if(str.compare("empty") == 0) {
            cout << q.empty() << "\n";
        }
        
        else if(str.compare("front") == 0) {
            if(q.empty()) cout << "-1" << "\n";
            else {
                cout << q.front() << "\n";
            }
        }
        
        else if(str.compare("back") == 0) {
            if(q.empty()) cout << "-1" << "\n";
            else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}