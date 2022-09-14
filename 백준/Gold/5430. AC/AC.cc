#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, temp = 0;
        bool cnt_reverse = false;
        string st, p;
        deque < int > dq;
        
        cin >> p;
        cin >> n;
        cin >> st;
        
        for(int i = 0; i < st.size(); i++) {
            if(st[i] - '0' >= 0 && st[i] - '0' < 10) {
                temp *= 10;
                temp += st[i] - '0';
            }
            else {
                if(temp != 0) {
                    dq.push_back(temp);
                    temp = 0;
                }
            }
        }
        
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') {
                if(cnt_reverse == false) cnt_reverse = true;
                else cnt_reverse = false;
            }
            else {
                if(dq.size() == 0) {
                    cout << "error" << endl;
                    break;
                }
                if(cnt_reverse) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
            
            if(i == p.size() - 1) {
                cout << "[";
                if(cnt_reverse) {
                    for(int i = dq.size() - 1; i >= 0; i--) {
                        cout << dq[i];
                        if(i != 0) cout << ",";
                    }
                }
                else {
                    for(int i = 0; i < dq.size(); i++) {
                        cout << dq[i];
                        if(i != dq.size() - 1) cout << ",";
                    }
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}