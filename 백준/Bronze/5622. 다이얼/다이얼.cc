#include <cstdio>
#define N 20

using namespace std;

char data[N];
int time;

void check(int node)
{
    switch(data[node]) {
        case 'A':
        case 'B':
        case 'C':
            time+=3;
            break;
        case 'D':
        case 'E':
        case 'F':
            time+=4;
            break;
        case 'G':
        case 'H':
        case 'I':
            time+=5;
            break;
        case 'J':
        case 'K':
        case 'L':
            time+=6;
            break;
        case 'M':
        case 'N':
        case 'O':
            time+=7;
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            time+=8;
            break;
        case 'T':
        case 'U':
        case 'V':
            time+=9;
            break;
        default:
            time+=10;
            break;
    }
}

int main()
{
    int cnt=0;
    scanf("%s",data);
    while(data[cnt]!='\0') {
        check(cnt);
        cnt++;
    }
    printf("%d",time);
    return 0;
}
