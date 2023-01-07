#include <string>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

const int multi = 65536;

map < string, int > mp1, mp2;
int mp1_size = 0;
int mp2_size = 0;

bool check(string temp) {
    if(temp[0] < 'a' || temp[0] > 'z') return false;
    if(temp[1] < 'a' || temp[1] > 'z') return false;
    return true;
}

void f_initialize(string &str1, string &str2) {
    for(int i = 0; i < str1.size(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for(int i = 0; i < str2.size(); i++) {
        str2[i] = tolower(str2[i]);
    }
    for(int i = 0; i < str1.size() - 1; i++) {
        string temp = str1.substr(i, 2);
        if(check(temp)) {
            if(mp1.find(temp) == mp1.end()) mp1.insert(make_pair(temp, 1));
            else mp1[temp]++;
            mp1_size++;
        }
    }
    
    for(int i = 0; i < str2.size() - 1; i++) {
        string temp = str2.substr(i, 2);
        if(check(temp)) {
            if(mp2.find(temp) == mp2.end()) mp2.insert(make_pair(temp, 1));
            else mp2[temp]++;
            mp2_size++;
        }
    }
} 

int solution(string str1, string str2) {
    int answer = 0;
    int sum = 0;
    int intersection = 0;
    f_initialize(str1, str2);
    
    for(map < string, int > :: iterator iter = mp2.begin(); iter != mp2.end(); iter++) {
        string temp = iter -> first;
        if(mp1.find(temp) != mp1.end()) intersection += min(mp1[temp], mp2[temp]);
    } 
    sum = mp1_size + mp2_size - intersection;
    return answer = (sum == 0) ? multi : floor(((double)intersection / (double)sum) * multi); 
}