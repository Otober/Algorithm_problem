#include <cstdio>
#define N 105

using namespace std;

int dy[N];
char data[N];

int main()
{
    int n,tcnt=0;
    scanf("%d",&n);
    while(n>0) {
        int cnt=0;
        n--;
        scanf("%s",data);
        while(data[cnt]!='\0') {
            if(dy[data[cnt]-'a'+1]==1) {
                tcnt--;
                break;
            }
            if(data[cnt]==data[cnt+1]);
            else dy[data[cnt]-'a'+1]=1;
            cnt++;
        }
        tcnt++;
        for(int i=0;i<=N;i++) {
            dy[i]=0;
            data[i]='\0';
        }
    }
    printf("%d",tcnt);
    return 0;
}