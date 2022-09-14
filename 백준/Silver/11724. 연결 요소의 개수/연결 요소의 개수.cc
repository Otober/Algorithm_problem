#include <cstdio>
#include <vector>
#define N 1005

using namespace std;

vector < int > adj[N*(N-1)/2];

int visit[N];
int cnt;

void connect(int node)
{
    visit[node]=1;
    for(int i=0;i<adj[node].size();i++) {
        int next=adj[node][i];
        if(visit[next]==0) {
            connect(next);
        }
    }
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        if(visit[i]==0) {
            cnt++;
            connect(i);
        }
    }
    printf("%d",cnt);
    return 0;
}
