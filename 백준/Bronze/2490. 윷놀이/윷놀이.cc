#include <cstdio>

using namespace std;

int main()
{
    for(int i=1;i<=3;i++) {
        int cnt=0;
        for(int j=1;j<=4;j++) {
            int temp;
            scanf("%d",&temp);
            if(temp==0) cnt++;
        }
        if(cnt>0) {
            printf("%c\n",'A'+cnt-1);
        }
        else {
            printf("E\n");
        }
    }
    return 0;
}
