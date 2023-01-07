#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue < int > pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    int sum = 0;
    for(int i = 0; i < enemy.size(); i++) {
        pq.push(-enemy[i]);
        if(pq.size() > k) {
            sum += -pq.top();
            pq.pop();
        }
        if(sum > n) {
            answer = i;
            break;
        }
    }
    return answer;
}