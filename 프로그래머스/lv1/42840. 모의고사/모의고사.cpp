#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> answer1 {1, 2, 3, 4, 5};
vector <int> answer2 {2, 1, 2, 3, 2, 4, 2, 5};
vector <int> answer3 {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == answer1[i % answer1.size()]) cnt1++;
        if(answers[i] == answer2[i % answer2.size()]) cnt2++;
        if(answers[i] == answer3[i % answer3.size()]) cnt3++;
    }
    int max_score = max(cnt1, max(cnt2, cnt3));
    if(max_score == cnt1) answer.push_back(1);
    if(max_score == cnt2) answer.push_back(2);
    if(max_score == cnt3) answer.push_back(3);
    return answer;
}