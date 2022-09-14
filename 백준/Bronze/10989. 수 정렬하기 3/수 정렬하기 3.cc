#include <cstdio>
#define N 10005

using namespace std;

int data[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int temp;
        scanf("%d",&temp);
        data[temp]++;
    }
    for(int i=1;i<=N-1;i++) {
        for(int j=1;j<=data[i];j++) {
            printf("%d\n",i);
        }
    }
    return 0;
}
