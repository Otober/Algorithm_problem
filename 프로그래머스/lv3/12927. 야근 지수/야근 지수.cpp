#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue < int > pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    while(n > 0) {
        n--;
        if(pq.top() != 0 ) pq.push(pq.top() - 1);
        if(!pq.empty()) pq.pop();
    }
    while(!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        answer += temp * temp;
    }
    return answer;
}