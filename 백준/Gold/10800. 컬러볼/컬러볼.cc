#include <cstdio>
#include <algorithm>
#define N 200005

using namespace std;

struct B {
	int c, s, n, d;
	bool operator()(B i, B j)
	{ return (i.n<j.n);
	}
}Data2[N];

int color[N];

struct A {
	int c, s, n, d;
	bool operator()(A i, A j)
	{ return ((i.s<j.s)||(i.s==j.s)&&(i.n < j.n));
	}
}Data1[N];


int main()
{
	int n,cnt=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &Data1[i].c, &Data1[i].s);
		Data1[i].n = i;
	}
	sort(Data1 + 1, Data1+1 + n, A());
	for (int i = 1; i <= n; i++) {
		int node = i;
		cnt += Data1[i].s;
		color[Data1[i].c] += Data1[i].s;
		Data1[i].d = cnt - color[Data1[i].c];
		while (1) {
			node--;
			if (Data1[i].c == Data1[node].c) continue;
			if (Data1[i].s == Data1[node].s) {
				Data1[i].d -= Data1[i].s;
			}
			else break;
		}
		Data2[i].c = Data1[i].c;
		Data2[i].s = Data1[i].s;
		Data2[i].n = Data1[i].n;
		Data2[i].d = Data1[i].d;
	}
	sort(Data2 + 1, Data2 + 1 + n, B());
	for (int i = 1; i <= n; i++) {
		printf("%d\n", Data2[i].d);
	}
	return 0;
}