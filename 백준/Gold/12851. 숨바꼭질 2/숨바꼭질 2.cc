#include <iostream>
#include <queue>
#define N 100005
#define INF 987654321
using namespace std;

priority_queue < pair <int, int > > pq;
int visit[N] = {};
int sec_max = INF;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    fill_n(visit, N, INF);
    pq.push(make_pair(-0, n));
    while(!pq.empty()) {
        int sec = -pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        if(loc > N || loc < 0) continue;
        if(visit[loc] < sec) continue;
        if(sec_max < sec) break;
        visit[loc] = sec;
        if(loc == k) {
            sec_max = sec;
            cnt++;
        }
        pq.push(make_pair(-(sec + 1), loc - 1));
        pq.push(make_pair(-(sec + 1), loc + 1));
        pq.push(make_pair(-(sec + 1), 2 * loc));
    }
    cout << sec_max << endl;
    cout << cnt << endl;
    return 0;
}