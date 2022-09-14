#include <cstdio>
#include <algorithm>
#include <limits.h>
#define N 5005

using namespace std;

struct A {
	int l, w;
	bool operator()(A i, A j)
	{
		if (i.l < j.l) return 1;
		else if (i.l == j.l) {
			if (i.w < j.w) return 1;
		}
		return 0;
	}
}Data[N];

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n,cnt=0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d %d", &Data[j].l, &Data[j].w);
		}
		sort(Data + 1, Data + 1 + n, A());
		while (1) {
			int visit = 1,temp=INT_MIN;
			cnt++;
			for (int k = 1; k <= n; k++) {
				if (Data[k].w == 0) continue;
				else if (Data[k].w >= temp) {
					visit = 0;
					temp = Data[k].w;
					Data[k].w = 0;
				}
			}
			if (visit == 1) break;
		}
		printf("%d\n", cnt-1);
	}
	return 0;
}
