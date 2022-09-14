#include <cstdio>
#define N 55

using namespace std;

int m,n;
int visit[N][N];
int data[N][N];
int ny[4]={0,1,0,-1},nx[4]={1,0,-1,0};

bool checked(int i,int j)
{
    if(i<0||i>m) return 0;
    if(j<0||j>n) return 0;
    if(data[i][j]==0) return 0;
    if(visit[i][j]==1) return 0;
    return 1;
}

void check(int i,int j)
{
    visit[i][j]=1;
    for(int k=0;k<4;k++) {
        if(checked(i+ny[k],j+nx[k])) {
            check(i+ny[k],j+nx[k]);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++) {
        int c;
        int cnt=0,tcnt=0;
        scanf("%d %d %d",&m,&n,&c);
        for(int i=1;i<=c;i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            data[a][b]=1;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(data[i][j]==1&&visit[i][j]==0) {
                    cnt++;
                    check(i,j);
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                visit[i][j]=0;
                data[i][j]=0;
            }
        }
    }
    return 0;
}
