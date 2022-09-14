#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

queue <int>pq;
char adj[10];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",adj);
        if(!strcmp(adj,"push")) {
            int node;
            scanf("%d",&node);
            pq.push(node);
        }
        else if(!strcmp(adj,"front")) {
            if(pq.empty()) printf("-1\n");
            else printf("%d\n",pq.front());
        }
        else if(!strcmp(adj,"back")) {
            if(pq.empty()) printf("-1\n");
            else printf("%d\n",pq.back());
        }
        else if(!strcmp(adj,"empty")) {
            printf("%d\n",pq.empty());
        }
        else if(!strcmp(adj,"size")) {
            printf("%d\n",pq.size());
        }
        else if(!strcmp(adj,"pop")) {
            if(!pq.empty()) {
                printf("%d\n",pq.front());
                pq.pop();
            }
            else printf("-1\n");
        }
        for(int j=0;j<10;j++) {
            adj[j]=NULL;
        }
    }
    return 0;
}
