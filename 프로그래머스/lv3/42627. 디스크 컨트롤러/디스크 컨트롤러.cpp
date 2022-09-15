#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator() (const vector < int > &a, const vector < int > &b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int idx = 0;
    priority_queue < vector < int >, vector < vector < int > >, cmp > pq;
    sort(jobs.begin(), jobs.end());
    
    while(idx < jobs.size() || !pq.empty()) {
        if(jobs.size() > idx && time >= jobs[idx][0]) {
            pq.push(jobs[idx++]);
            continue;
        }
        if(!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else time = jobs[idx][0];
    }
    return answer / jobs.size();
}