#include <cstdio>
#include <queue>
#include <limits.h>
#define N 100005

using namespace std;

queue<pair<int,int> >pq;

bool visit[N]={false};

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    pq.push(make_pair(n,0));
    while(!pq.empty()) {
        int node=pq.front().first;
        int cnt=pq.front().second;
        pq.pop();
        if(node==k) {
            printf("%d",cnt);
            break;
        }
        if(node<0||node>N) continue;
        if(visit[node]==1) continue;
        visit[node]=true;
        pq.push(make_pair(node+1,cnt+1));
        pq.push(make_pair(node-1,cnt+1));
        pq.push(make_pair(node*2,cnt+1));
    }
    return 0;
}
