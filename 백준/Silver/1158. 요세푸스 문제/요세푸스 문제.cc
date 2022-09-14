#include <cstdio>
#include <queue>
#define N 100005

using namespace std;

queue < int > pq;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        pq.push(i);
    }
    printf("<");
    while(!pq.empty()) {
        for(int i=1;i<=m-1;i++) {
            pq.push(pq.front());
            pq.pop();
        }
        printf("%d",pq.front());
        pq.pop();
        if(!pq.empty()) printf(", ");
    }
    printf(">");
    return 0;
}
