#include <cstdio>
#define N 305

using namespace std;

int data[N];
int dp[N];

int max(int a,int b)
{
    return (a>b) ? a: b;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data[i]);
    }
    dp[1]=data[1];
    dp[2]=max(data[1]+data[2],data[2]);
    dp[3]=max(data[1]+data[3],data[2]+data[3]);
    for(int i=4;i<=n;i++) {
        dp[i]=max(dp[i-2]+data[i],dp[i-3]+data[i-1]+data[i]);
    }
    printf("%d",dp[n]);
    return 0;
}
