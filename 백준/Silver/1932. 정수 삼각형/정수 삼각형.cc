#include <cstdio>
#define N 505
#define MAX(a,b)((a>b) ? a : b)

using namespace std;

int data[N][N];
int dy[N][N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            scanf("%d",&data[i][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            dy[i][j]=data[i][j]+MAX(dy[i-1][j],dy[i-1][j-1]);
        }
    }
    int temp=0;
    for(int i=1;i<=n;i++) {
        if(temp<dy[n][i]) temp=dy[n][i];
    }
    printf("%d",temp);
    return 0;
}
