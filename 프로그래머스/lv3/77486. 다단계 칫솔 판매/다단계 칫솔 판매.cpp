#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

const int N = 10005;

int parent[N] = {};
int result[N] = {};

map < string, int > m;


void f_parent(int child, int cost) {
    if(child == -1) return;
    int temp = cost * 0.1;
    result[child] += (cost - temp);
    f_parent(parent[child], temp);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    m.insert(make_pair("minho", 0));
    parent[0] = -1;
    
    for(int i = 0; i < enroll.size(); i++) {
        m.insert(make_pair(enroll[i], i + 1));
    }
    for(int i = 0; i < referral.size(); i++) {
        if(referral[i] == "-") parent[i + 1] = 0;
        else parent[i + 1] = m[referral[i]];
    }
    for(int i = 0; i < seller.size(); i++) {
        f_parent(m[seller[i]], amount[i] * 100);
    }
    for(int i = 0; i < enroll.size(); i++) {
        answer.push_back(result[i + 1]);
    }
    return answer;
}