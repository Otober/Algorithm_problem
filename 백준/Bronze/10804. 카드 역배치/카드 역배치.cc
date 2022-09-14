#include <stdio.h>

using namespace std;

int main()
{
    int data[21],temp;
    for(int i=1;i<=20;i++) {
        data[i]=i;
    }
    for(int i=1;i<=10;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        while(a<b) {
            temp=data[b];
            data[b]=data[a];
            data[a]=temp;
            b--;
            a++;
        }
    }
    for(int i=1;i<=20;i++) {
        printf("%d ",data[i]);
    }
    return 0;
}
