#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector < int > answer;
    vector < int > v;
    v.push_back(score[0]);
    answer.push_back(score[0]);
    for(int i = 1; i < score.size(); i++) {
        int temp = score[i];
        for(int j = 0; j < v.size(); j++) {
            if(v[j] < temp) {
                v.insert(v.begin() + j, temp);
                break;
            }
            if(j == v.size() - 1) {
                v.push_back(temp);
                break;
            }
        }
        if(v.size() > k) v.erase(v.end() - 1);
        answer.push_back(*(v.end() - 1));
    }
    return answer;
}