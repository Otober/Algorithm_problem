#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector < int > temp = emergency;
    sort(temp.begin(), temp.end(), greater<>());
    for(int i = 0; i < emergency.size(); i++) {
        for(int j = 0; j < temp.size(); j++) {
            if(emergency[i] == temp[j]) {
                answer.push_back(j + 1);
                break;
            }
        }
    }
    return answer;
}