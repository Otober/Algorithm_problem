#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

map < string, int > m;

void f_initialize() {
    m.insert(make_pair("R", 0));
    m.insert(make_pair("T", 0));
    m.insert(make_pair("F", 0));
    m.insert(make_pair("C", 0));
    m.insert(make_pair("M", 0));
    m.insert(make_pair("J", 0));
    m.insert(make_pair("A", 0));
    m.insert(make_pair("N", 0));
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    f_initialize();
    for(int i = 0; i < survey.size(); i++) {
        choices[i] -= 4;
        if(choices[i] > 0) m[survey[i].substr(1, 1)] += choices[i];
        else if(choices[i] < 0) m[survey[i].substr(0,1)] += -choices[i];
    }
    if(m["R"] >= m["T"]) answer += "R";
    else answer += "T";
    if(m["C"] >= m["F"]) answer += "C";
    else answer += "F";
    if(m["J"] >= m["M"]) answer += "J";
    else answer += "M";
    if(m["A"] >= m["N"]) answer += "A";
    else answer += "N";
    return answer; 
}