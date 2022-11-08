#include <string>
#include <vector>

using namespace std;

const int N = 10;

bool visit[N] = {};

int solution(vector<int> numbers) {
    int answer = -1;
    for(int i = 0; i < numbers.size(); i++) {
        visit[numbers[i]] = true;
    }
    for(int i = 0; i < N; i++) {
        if(!visit[i]) answer += i;
    }
    if(answer != -1) answer += 1; 
    return answer;
}