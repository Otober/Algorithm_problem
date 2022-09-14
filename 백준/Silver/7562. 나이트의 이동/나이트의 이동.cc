#include <cstdio>
#include <queue>
#define N 305
using namespace std;

queue <pair<int, int> >pq;
queue <int>cnt;

int ny[8]={2,1,-1,-2,-2,-1,1,2};
int nx[8]={1,2,2,1,-1,-2,-2,-1};
int visit[N][N];

bool check(int y,int x,int l)
{
    if(visit[y][x]==1) return 0;
    if(y<0||y>=l) return 0;
    if(x<0||x>=l) return 0;
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int ex,ey;
        int sx,sy;
        int l;
        scanf("%d",&l);
        scanf("%d %d",&sy,&sx);
        scanf("%d %d",&ey,&ex);
        pq.push(make_pair(sy,sx));
        cnt.push(0);
        visit[sy][sx]=1;
        while(1) {
            int y=pq.front().first;
            int x=pq.front().second;
            int count=cnt.front();
            pq.pop();
            cnt.pop();
            if(y==ey&&x==ex) {
                printf("%d\n",count);
                break;
            }
            for(int i=0;i<8;i++) {
                int dy=y+ny[i];
                int dx=x+nx[i];
                if(check(dy,dx,l)) {
                    visit[dy][dx]=1;
                    pq.push(make_pair(dy,dx));
                    cnt.push(count+1);
                }
            }
        }
        for(int i=0;i<l;i++) {
            for(int j=0;j<l;j++) {
                visit[i][j]=0;
            }
        }
        while(!pq.empty()) {
            pq.pop();
            cnt.pop();
        }
    }
    return 0;
}
