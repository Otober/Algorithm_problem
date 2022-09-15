#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector < int > answer;
    vector < int > v;
    for(int i = 0; i < operations.size(); i++) {
        if(operations[i][0] == 'I') {
            int num = stoi(operations[i].substr(2));
            v.push_back(num);
            sort(v.begin(), v.end());
        }
        else {
            if(operations[i] == "D 1") {
                if(!v.empty()) v.pop_back();
            }
            else if(operations[i] == "D -1") {
                if(!v.empty()) v.erase(v.begin());
            }
        }
    }
    if(v.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(v[v.size() - 1]);
        answer.push_back(v[0]);
    }
    return answer;
}