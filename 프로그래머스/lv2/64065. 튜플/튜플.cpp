#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void f_detach(vector < pair < int, vector < int > > > &tuple, string &s) {
    int idx = 1;
    int i = 0;
    vector < int > v;
    bool flag = false;
    
    for(int j = 0; j < s.size(); j++) {
        if(s[j] == '{') continue;
        if(s[j] == '}' || s[j] == ',') {
            if(flag) {
                int num;
                if(j - i == 1) num = s[i] - '0';
                else num = stoi(s.substr(i, j - i));
                v.push_back(num);
                if(s[j] == '}') {
                    tuple.push_back(make_pair(v.size(), v));
                    v.clear();
                }
                flag = false;
            }
        }
        else {
            if(!flag) {
                i = j;
                flag = true;
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    vector < pair < int, vector < int > > > tuple;
    
    set < int > chk;
    
    f_detach(tuple, s);
    sort(tuple.begin(), tuple.end());
    
    for(pair < int, vector < int > > p : tuple) {
        for(int num : p.second) {
            if(chk.find(num) == chk.end()) {
                chk.insert(num);
                answer.push_back(num);
            }
        }
    }
    return answer;
}