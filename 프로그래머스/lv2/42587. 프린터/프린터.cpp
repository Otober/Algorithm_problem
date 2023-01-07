#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue < pair < int, int > > q;
    priority_queue < int > pq;
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        int importance = q.front().first;
        int document = q.front().second;
        q.pop();
        
        if(importance == pq.top()) {
            pq.pop();
            answer++;
            if(document == location) break;
        }
        else q.push(make_pair(importance, document));
    }
    return answer;
}