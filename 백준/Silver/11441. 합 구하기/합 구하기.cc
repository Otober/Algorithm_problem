#include <cstdio>
#define N 100005

using namespace std;

int sum[N];

int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int temp;
        scanf("%d",&temp);
        sum[i]=sum[i-1]+temp;
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}
