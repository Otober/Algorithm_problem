#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,temp,node;
    scanf("%d %d",&a,&b);
    node=a;
    temp=0;
    while(node>0) {
        temp*=10;
        temp+=node%10;
        node/=10;
    }
    a=temp;
    node=b;
    temp=0;
    while(node>0) {
        temp*=10;
        temp+=node%10;
        node/=10;
    }
    b=temp;
    printf("%d",max(a,b));
    return 0;
}
