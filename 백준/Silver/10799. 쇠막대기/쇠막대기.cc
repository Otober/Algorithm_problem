#include<cstdio>

#define N 100005

char str[N];

int main()
{
    int cnt=0,tcnt=0;
    scanf("%s",&str);
    for(int i=0;;i++) {
        if(str[i]=='\0') break;
        if(str[i]=='(') tcnt++;
        else {
            tcnt--;
            if(str[i-1]=='(') cnt+=tcnt;
            else cnt++;
        }
    }
    printf("%d",cnt);
}
