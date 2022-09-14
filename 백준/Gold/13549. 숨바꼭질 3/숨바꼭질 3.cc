#include <iostream>
#include <queue>
#define N 100005
using namespace std;

priority_queue < pair <int, int > > pq;
bool visit[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    pq.push(make_pair(-0, n));
    while(!pq.empty()) {
        int sec = -pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        if(loc > N || loc < 0) continue;
        if(visit[loc] == true) continue;
        visit[loc] = true;
        if(loc == k) {
            cout << sec << endl;
            break;
        }
        pq.push(make_pair(-(sec + 1), loc - 1));
        pq.push(make_pair(-(sec + 1), loc + 1));
        pq.push(make_pair(-sec, 2 * loc));
    }
    return 0;
}