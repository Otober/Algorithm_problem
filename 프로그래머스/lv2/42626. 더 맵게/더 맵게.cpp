#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue < int > pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i : scoville) {
        pq.push(-i);
    }
    
    while(pq.size() >= 2) {
        if(-pq.top() >= K) break;
        int first = -pq.top();
        pq.pop();
        int second = -pq.top();
        pq.pop();
        
        pq.push(-(first + (2 * second)));
        answer++;
    }
    if(-pq.top() < K) answer = -1;
    return answer;
}