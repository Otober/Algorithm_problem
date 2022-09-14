#include <cstdio>
#include <algorithm>
#define N 1000005

using namespace std;

int data[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data[i]);
    }
    sort(data+1,data+1+n);
    for(int i=1;i<=n;i++) {
        printf("%d\n",data[i]);
    }
    return 0;
}
