#include <algorithm>
#include <string>
#include <vector>


#include <iostream>

using namespace std;

bool cmp (pair < pair < int, string >, pair < string, string > > &a, pair < pair < int, string >, pair < string, string > > &b) {
    string string_first = a.first.second;
    string string_second = b.first.second;
    transform(string_first.begin(), string_first.end(), string_first.begin(), ::tolower);
    transform(string_second.begin(), string_second.end(), string_second.begin(), ::tolower);
    if(string_first == string_second) {
        int num_first = stoi(a.second.first);
        int num_second = stoi(b.second.first);
        if(num_first == num_second) {
            return a.first.first < b.first.first;
        }
        else {
            if(num_first < num_second) return true;
            else return false;
        }
    }
    else {
        if(string_first < string_second) return true;
        else return false;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector < pair < pair < int, string >, pair < string, string > > > v;
    for(int i = 0; i < files.size(); i++) {
        string st = files[i];
        string head = "";
        string number = "";
        string tail = "";
        int j = 0;
        for(j; j < st.size(); j++) {
            if(st[j] >= '0' && st[j] <= '9') {
                head = st.substr(0, j);
                break;
            }
        }
        int before = j;
        for(j; j < st.size(); j++) {
            if(st[j] < '0' || st[j] > '9') {
                number = st.substr(before, j - before);
                tail = st.substr(j);
                break;
            }
        }
        if(j == st.size()) {
            number = st.substr(before);
        }
        v.push_back(make_pair(make_pair(i, head), make_pair(number, tail)));
        cout << i << "|" << head << "|" << number << "|" << tail << endl;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        string temp = v[i].first.second + v[i].second.first + v[i].second.second;
        answer.push_back(temp);
    }
    return answer;
}