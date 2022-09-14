#include <cstdio>

using namespace std;

int data[10];

int main()
{
    int sum=1;
    for(int i=1;i<=3;i++) {
        int temp;
        scanf("%d",&temp);
        sum*=temp;
    }
    while(sum>0) {
        data[sum%10]++;
        sum/=10;
    }
    for(int i=0;i<=9;i++) {
        printf("%d\n",data[i]);
    }
    return 0;
}
