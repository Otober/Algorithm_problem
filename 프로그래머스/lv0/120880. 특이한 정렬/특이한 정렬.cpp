#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector < pair < int, int > > v;

bool f_compare(pair < int, int > &a, pair < int, int > &b) {
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    for(int i = 0; i < numlist.size(); i++) {
        v.push_back(make_pair(abs(numlist[i] - n), numlist[i]));
    }
    sort(v.begin(), v.end(), f_compare);
    for(int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].second);
    }
    return answer;
}