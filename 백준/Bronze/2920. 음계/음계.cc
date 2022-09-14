#include <cstdio>
#define N 10

using namespace std;

int data[N];

int main()
{
    int uflag=1,dflag=1;
    int temp;
    for(int i=1;i<=8;i++) {
        scanf("%d",&data[i]);
        if(i==1) temp=data[i];
        else {
            if(temp-1!=data[i]) {
                dflag=0;
            }
            if(temp+1!=data[i]) {
                uflag=0;
            }
            temp=data[i];
        }
    }
    if(uflag==0&&dflag==0) printf("mixed\n");
    else if(uflag==1) printf("ascending\n");
    else printf("descending\n");
    return 0;
}
