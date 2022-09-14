#include <cstdio>
#include <algorithm>
#define N 100005
#define INT_MAX 999999999

using namespace std;

long long int data[N];
long long int dy[N];
long long int tmax=-INT_MAX;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&data[i]);
    }
    for(int i=1;i<=n;i++) {
        dy[i]=max(dy[i-1]+data[i],data[i]);
        tmax=max(tmax,dy[i]);
    }
    printf("%d",tmax);
    return 0;
}
