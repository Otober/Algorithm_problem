#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair < double, int > &a, pair < double, int > &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector < pair <double, int > > fail;
    sort(stages.begin(), stages.end());
    for(int i = 1; i <= N; i++) {
        int challenge = 0;
        int miss = 0;
        for(int j = 0; j < stages.size(); j++) {
            if(i > stages[j]) miss++;
            else if(i == stages[j]) challenge++;
            else break;
        }
        int clear = stages.size() - miss;
        if(clear == 0) fail.push_back({(double)0, i});
        else fail.push_back({(double)challenge / clear, i});
    }
    sort(fail.begin(), fail.end(), cmp);
    for(int i = 0; i < N; i++) {
        answer.push_back(fail[i].second);
        cout << fail[i].first << " " << fail[i].second << endl;
    }
    return answer;
}