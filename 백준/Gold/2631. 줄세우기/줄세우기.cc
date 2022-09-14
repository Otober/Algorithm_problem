#include <cstdio>
#include <limits.h>
#define N 1000005

using namespace std;

int data[N];
int dy[N];

int main()
{
    int n,tmax=INT_MIN;
    int cnt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data[i]);
    }
    dy[1]=1;
    for(int i=2;i<=n;i++) {
        int temp=0;
        for(int j=1;j<i;j++) {
            if(data[j]<data[i]) {
                if(dy[j]>temp) {
                    temp=dy[j];

                }
            }
        }
        dy[i]=temp+1;
        if(tmax<dy[i]) tmax=dy[i];
    }
    printf("%d",n-tmax);
    return 0;
}
