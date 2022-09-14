#include <cstdio>
#define N 100

long long int data[N];

int main()
{
	int n;
	scanf("%d", &n);
	data[1] = 1;
	for (int i = 2; i <= n; i++) {
		data[i] = data[i - 1] + data[i - 2];
	}
	printf("%lld", data[n]);
	return 0;
}