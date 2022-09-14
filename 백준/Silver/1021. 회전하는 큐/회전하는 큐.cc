#include <iostream>
#include <deque>

using namespace std;

deque < int > dq;

bool f_min(const int &a, const int &b) {
    return a < b ? true : false;
}

int main() {
    int n,m;
    int cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    for(int i = 0; i < m; i++) {
        int temp;
        int dq_cnt = dq.size();
        cin >> temp;
        
        for(int i = 0; i < dq_cnt; i++) {
            if(temp == dq[i]) {
                if(f_min(i, (dq_cnt - i))) {
                    for(int j = 0; j < i; j++) {
                        dq.push_back(dq.front());
                        dq.pop_front();
                        cnt++;
                    }
                }
                else {
                    for(int j = 0; j < dq_cnt - i; j++) {
                        dq.push_front(dq.back());
                        dq.pop_back();
                        cnt++;
                    }
                }
                dq.pop_front();
                break;
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}