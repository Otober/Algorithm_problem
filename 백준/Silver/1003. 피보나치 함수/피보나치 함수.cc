#include <cstdio>
#define N 50

int data[N]={1,1};

int fibonacci(int n){
    if(n<=1) return data[n];
    else {
        if(data[n]>0) return data[n];
    }
    return data[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main ()
{
    int t;
    scanf("%d",&t);
    while(t>0) {
        t--;
        int n;
        scanf("%d",&n);
        if(n==0) printf("1 0\n");
        else if(n==1) printf("0 1\n");
        else {
            fibonacci(n);
            printf("%d %d\n",data[n-2],data[n-1]);
        }
    }
	return 0;
}
