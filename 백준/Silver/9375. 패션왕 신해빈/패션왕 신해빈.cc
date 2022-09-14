#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        vector < pair < int, string> >adj;
        cin >> n;
        for(int i = 0; i < n; i++) {
            string name_str, str;
            cin >> name_str >> str;
            for(int i = 0; i <= adj.size(); i++) {
                if(i == adj.size()) {
                    adj.push_back(make_pair(1,str));
                    break;
                }
                else if(str == adj[i].second) {
                    adj[i].first++;
                    break;
                }
            }
        }
        
        int result = 1;
        for(int i = 0; i < adj.size(); i++) {
            result *= adj[i].first + 1;
        }
        result--;
        cout << result << endl;
    }
    return 0;
}