#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include <iostream>
using namespace std;

int column;
vector < string > combination;

bool cmp(string &a, string &b) {
    if(a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

void Combination(int k = 0, string temp = "") {
    for(int i = k; i < column; i++) {
        temp += to_string(i);
        combination.push_back(temp);
        Combination(i + 1, temp);
        temp = temp.substr(0, temp.length() - 1);
    }
}

bool Candidate(vector < vector < string > > &relation, string st) {
    map < string, int > mp;
    for(int i = 0; i < relation.size(); i++) {
        string temp = "";
        for(int j = 0; j < st.size(); j++) {
            int num = st[j] - '0';
            temp += relation[i][num] + " ";
        }
        if(mp[temp]) return false;
        else mp[temp]++;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    column = relation[0].size();
    Combination();
    sort(combination.begin(), combination.end(), cmp);
    
    for(int i = 0; i < combination.size(); i++) {
        if(Candidate(relation, combination[i])) {
            string temp = combination[i];
            
            for(int j = combination.size() - 1; j >= i; j--) {
                bool flag = true;
                for(int t = 0; t < temp.size(); t++) {
                    if(combination[j].find(temp[t]) == string::npos) {
                        flag = false;
                        break;
                    }
                }
                if(flag) combination.erase(combination.begin() + j);
            }
            i--;
            answer++;
        }
    }
    return answer;
}