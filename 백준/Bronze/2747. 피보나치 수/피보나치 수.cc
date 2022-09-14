#include <cstdio>
#define N 50

using namespace std;

long long int data[N];

int main()
{
    int n;
    scanf("%lld",&n);
    data[1]=1;
    for(int i=2;i<=n;i++) {
        data[i]=data[i-1]+data[i-2];
    }
    printf("%lld",data[n]);
    return 0;
}
