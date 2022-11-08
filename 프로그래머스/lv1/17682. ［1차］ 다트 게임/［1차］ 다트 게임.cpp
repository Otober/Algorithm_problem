#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    vector < int > scoreboard(3);
    for(int i = 0; i < 3; i++) {
        int score = 0;
        char bonus;
        char option;
        while('0' <= dartResult[idx] && dartResult[idx] <= '9') {
            score *= 10;
            score += dartResult[idx++] - '0';
        }
        bonus = dartResult[idx++];
        if(bonus == 'S') scoreboard[i] = (int)pow(score,1);
        else if(bonus == 'D') scoreboard[i] = (int)pow(score, 2);
        else if(bonus == 'T') scoreboard[i] = (int)pow(score, 3);
        
        if(dartResult[idx] == '*' || dartResult[idx] == '#') {
            option = dartResult[idx++];
            if(option == '*') {
                scoreboard[i] *= 2;
                if(i != 0) scoreboard[i - 1] *= 2;
            }
            else if(option == '#') scoreboard[i] = -scoreboard[i];
        }
    }
    for(int i = 0; i < scoreboard.size(); i++) {
        answer += scoreboard[i];
    }
    return answer;
}