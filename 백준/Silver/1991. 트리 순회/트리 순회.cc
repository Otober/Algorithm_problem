#include <cstdio>

using namespace std;

int data[28][4];
int visit[28];

bool check(int node,int i)
{
    if(data[node][i]==0) return 0;
    return 1;
}

void preorder(int node)
{
    printf("%c",node+'A'-1);
    for(int i=1;i<=2;i++) {
        if(check(node,i)) {
            preorder(data[node][i]);
        }
    }
    return;
}

void postorder(int node)
{
    for(int i=1;i<=2;i++) {
        if(check(node,i)) {
            postorder(data[node][i]);
        }
    }
    printf("%c",node+'A'-1);
}

void inorder(int node)
{
    if(node!=0) {
        inorder(data[node][1]);
        printf("%c",node+'A'-1);
        inorder(data[node][2]);
    }
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++) {
        char a,b,c;
        scanf("%c %c %c\n",&a,&b,&c);
        if(b!='.') {
            data[a-'A'+1][1]=b-'A'+1;
        }
        if(c!='.') {
            data[a-'A'+1][2]=c-'A'+1;
        }
    }
    preorder(1);
    printf("\n");
    inorder(1);
    printf("\n");
    postorder(1);
    printf("\n");
    return 0;
}
