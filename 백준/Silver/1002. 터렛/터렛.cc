#include <cstdio>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t>0) {
        t--;
        int x1,y1,r1,x2,y2,r2;
        double range;
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        range=sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
        if(x1==x2&&y1==y2) {
            if(r1==r2) printf("-1\n");
            else printf("0\n");
        }
        else {
            if(r1+r2>range&&abs(r1-r2)<range) printf("2\n");
            else if(r1+r2==range||abs(r1-r2)==range) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
