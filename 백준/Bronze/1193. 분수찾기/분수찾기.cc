#include <cstdio>

using namespace std;

int main()
{
    int n;
    int cnt=1,tcnt=1;
    scanf("%d",&n);
    while(cnt+tcnt<=n) {
        cnt+=tcnt;
        tcnt++;
    }
    if(tcnt%2==1) printf("%d/%d",tcnt-(n-cnt),1+(n-cnt));
    else printf("%d/%d",1+(n-cnt),tcnt-(n-cnt));
    return 0;
}
