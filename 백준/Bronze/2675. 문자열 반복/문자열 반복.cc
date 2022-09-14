#include <cstdio>
#define N 1005

using namespace std;

char data[N];

int main()
{
    int i=0,n,t;
    scanf("%d\n",&t);
    while(t>0) {
        t--;
        scanf("%d %s\n",&n,data);
        while(data[i]!=NULL) {
            for(int j=1;j<=n;j++) {
                printf("%c",data[i]);
            }
            i++;
        }
        printf("\n");
        for(int k=0;k<=i;k++) {
            data[k]=NULL;
        }
        i=0;
    }
    return 0;
}
