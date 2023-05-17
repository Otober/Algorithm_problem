#include <string>
#include <vector>

using namespace std;

const int N = 500000;

long long dp[N] = {};

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector < long long > v;
    for(int i = 0; i < sequence.size(); i++) {
        int temp;
        if(i % 2 == 0) temp = sequence[i] * -1;
        else temp = sequence[i];
        v.push_back(temp);
    }
    dp[0] = v[0];
    answer = (answer > dp[0]) ? answer : dp[0];
    for(int i = 1; i < v.size(); i++) {
        dp[i] = ((dp[i - 1] > 0) ? dp[i - 1] : 0 ) + v[i];
        answer = (answer > dp[i]) ? answer : dp[i];
    }

    v.clear();
    
    for(int i = 0; i < sequence.size(); i++) {
        int temp;
        if(i % 2 == 1) temp = sequence[i] * -1;
        else temp = sequence[i];
        v.push_back(temp);
    }
    
    dp[0] = v[0];
    answer = (answer > dp[0]) ? answer : dp[0];
    for(int i = 1; i < v.size(); i++) {
        dp[i] = ((dp[i - 1] > 0) ? dp[i - 1] : 0 ) + v[i];
        answer = (answer > dp[i]) ? answer : dp[i];
    }
    return answer;
}