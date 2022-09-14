#include <cstdio>
#include <algorithm>
#define N 30

using namespace std;

int n,cnt,tcnt;
int data[N][N];
int visit[N][N];
int path[N*N];

bool check(int y,int x)
{
    if(visit[y][x]==1) return 0;
    if(data[y][x]==0) return 0;
    return 1;
}

void apart(int y,int x)
{
    int ny[4]={0,1,0,-1},nx[4]={1,0,-1,0};
    int dy,dx;
    visit[y][x]=1;
    cnt++;
    for(int i=0;i<4;i++) {
        dy=ny[i]+y;
        dx=nx[i]+x;
        if(check(dy,dx)) {
            apart(dy,dx);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%1d",&data[i][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(data[i][j]==1) {
                if(visit[i][j]==0) {
                    tcnt++;
                    apart(i,j);
                    path[tcnt]=cnt;
                    cnt=0;
                }
            }
        }
    }
    printf("%d\n",tcnt);
    sort(path+1,path+1+tcnt);
    for(int i=1;i<=tcnt;i++) {
        printf("%d\n",path[i]);
    }
    return 0;
}
