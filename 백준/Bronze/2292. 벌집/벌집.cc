#include <cstdio>

using namespace std;

int main()
{
    long long int n,data=1,temp=6,cnt=1;
    scanf("%lld",&n);
    while(data<n) {
        cnt++;
        data+=temp;
        temp+=6;
    }
    printf("%d",cnt);
    return 0;
}
