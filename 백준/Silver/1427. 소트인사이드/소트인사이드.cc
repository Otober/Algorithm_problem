#include <cstdio>
#include <algorithm>
#define N 15

using namespace std;

int data[N];

int main()
{
    int n,cnt=0;
    scanf("%d",&n);
    while(n>0) {
        cnt++;
        data[cnt]=n%10;
        n/=10;
    }
    sort(data+1,data+1+cnt);
    for(int i=cnt;i>=1;i--) {
        printf("%d",data[i]);
    }
    return 0;
}
