#include <cstdio>
#include <algorithm>

using namespace std;

int data[4];

int main()
{
    int a,b,c;
    scanf("%d %d %d",&data[1],&data[2],&data[3]);
    sort(data+1,data+4);
    printf("%d",data[2]);
    return 0;
}
