#include <cstdio>
#define N 105

int main()
{
	long long int dy[N];
	int t,n;
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 1;
	dy[3] = 1;
	dy[4] = 2;
	dy[5] = 2;
	dy[6] = 3;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 7; j <= n; j++) {
			dy[j] = dy[j - 5] + dy[j - 1];
		}
		printf("%lld\n", dy[n]);
	}
	return 0;
}