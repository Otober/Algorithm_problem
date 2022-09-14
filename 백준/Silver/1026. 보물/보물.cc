#include <cstdio>
#include <algorithm>
#define N 55

using namespace std;

int a[N];
int b[N];

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) {
        sum+=a[i]*b[n-i+1];
    }
    printf("%d",sum);
    return 0;
}
