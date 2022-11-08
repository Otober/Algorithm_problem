#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size());
    vector < pair < double, int > > v;
    for(int i = 0; i < score.size(); i++) {
        v.push_back(make_pair((score[i][0] + score[i][1]) / 2.0, i));
    }
    sort(v.begin(), v.end(), greater<>());
    int index = 1;
    for(int i = 0; i < v.size(); i++) {
        answer[v[i].second] = index;
        index++;
        if(i > 0) {
            if(v[i - 1].first == v[i].first) answer[v[i].second] = answer[v[i - 1].second];
        }
    }
    return answer;
}