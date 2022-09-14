#include <cstdio>
#define N 1005

int main()
{
	int dy[N], n;
	scanf("%d", &n);
	dy[0] = 1;
	dy[1] = 1;
	for (int i = 2; i <= n; i++) {
		dy[i] = (dy[i - 1] + dy[i - 2])%10007;
	}
	printf("%d", dy[n]);
	return 0;
}