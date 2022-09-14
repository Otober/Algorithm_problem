#include <cstdio>
#define N 10005
#define MAX(a,b) ((a>b) ? a : b)

using namespace std;

int data[N];
int dy[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data[i]);
    }
    for(int i=1;i<=n;i++) {
        dy[i]=MAX(dy[i-3]+data[i-1]+data[i],dy[i-2]+data[i]);
        dy[i]=MAX(dy[i-1],dy[i]);
    }
    printf("%d",dy[n]);
    return 0;
}
