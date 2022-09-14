#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t) {
        t--;
        long long int x,y;
        long long int temp;
        long long int cnt=0;
        scanf("%lld %lld",&x,&y);
        temp=y-x;
        while(cnt*cnt<temp) cnt++;
        if(cnt*(cnt-1)>=temp) printf("%lld\n",cnt*2-2);
        else printf("%lld\n",cnt*2-1);
    }
    return 0;
}
