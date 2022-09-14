#include <cstdio>

using namespace std;

int main()
{
    int n,flag=0;
    scanf("%d",&n);
    for(int i=0;;i++) {
        if(flag==1) break;
        if(i*3>n) {
            printf("-1");
            break;
        }
        for(int j=0;;j++) {
            if(j*5+i*3==n) {
                flag=1;
                printf("%d",i+j);
                break;
            }
            if(j*5+i*3>n) break;
        }
    }
    return 0;
}
