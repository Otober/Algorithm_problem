#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector < int >adj[10005];
queue < int > q;

int visit1[1005];
int visit2[1005];
int data[1005][1005];

bool check(int node,int next)
{
    if(visit1[next]==1) return 0;
    return 1;
}

void bfs(int node)
{
    q.push(node);
    visit2[node]=1;
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        visit2[now]=1;
        printf("%d ",now);
        for(int i=0;i<adj[now].size();i++) {
            int next=adj[now][i];
            if(visit2[next]==0) {
                visit2[next]=1;
                q.push(next);
            }
        }
    }
}

void dfs(int node)
{
    visit1[node]=1;
    printf("%d ",node);
    for(int i=0;i<(int)adj[node].size();i++) {
        int next=adj[node][i];
        if(check(node,next)) {
            dfs(next);
        }
    }
}

int main()
{
    int n,m,v;
    scanf("%d %d %d",&n,&m,&v);
    for(int i=1;i<=m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        data[a][b]=data[b][a]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(data[i][j]==1) {
                adj[i].push_back(j);
            }
        }
    }
    dfs(v);
    printf("\n");
    bfs(v);
    return 0;
}
