#include <cstdio>
#include <algorithm>
#define N 10005

using namespace std;

int main()
{
    long long int m=0;
    int data[N];
    int n;
    int limit=0;
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data[i]);
    }
    sort(data+1,data+n+1);
    scanf("%lld",&m);
    for(int i=1;i<=n;i++) {
        sum+=data[i];
        limit=data[i];
        if(sum+limit*(n-i)>=m) {
            int temp=(sum+limit*(n-i))-m;
            int dap=temp/(n-i+1)+1;
            if(temp%(n-1)==0) dap--;
            printf("%d",limit-dap);
            break;
        }
        if(n==i) {
            printf("%d",data[n]);
            break;
        }
    }
    return 0;
}
