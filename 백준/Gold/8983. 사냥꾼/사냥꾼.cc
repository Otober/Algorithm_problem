#include <cstdio>
#include <algorithm>
#define N 1000000005
#define M 100005

using namespace std;

struct A{
    int y,x;
    bool operator()(A i,A j)
    {
        if(i.x<j.x) return 1;
        else if(i.x==j.x) {
            if(i.y<j.y) return 1;
        }
        return 0;
    }
}data[M];

int shoot[M];

int main()
{
    int n,m;
    int cnt=0;
    long long int l;
    scanf("%d %d %lld",&m,&n,&l);
    for(int i=1;i<=m;i++) {
        scanf("%d",&shoot[i]);
    }
    sort(shoot+1,shoot+1+m);
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&data[i].x,&data[i].y);
    }
    sort(data+1,data+1+n,A());
    int tmax=1;
    for(int i=1;i<=n;i++) {
        for(int j=tmax;j<=m;j++) {
            if(data[i].y>l) break;
            if(shoot[m]+l<data[i].x) break;
            if(shoot[j]-l>data[i].x) break;
            if(shoot[j]+l<data[i].x) {
                tmax=j;
                continue;
            }
            int temp=shoot[j]-data[i].x;
            if(temp<0) temp=-temp;
            if(l>=temp+data[i].y) {
                cnt++;
                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
