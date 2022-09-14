#include <cstdio>

long long int n;
int k, q;

long long check(long long node)
{
	return (node + k - 2) / k;
}

int main()
{
	scanf("%lld %d %d", &n, &k, &q);
	for (int i = 1; i <= q; i++) {
		long long int l, r;
		scanf("%lld %lld", &l, &r);
		if (k == 1) {
			(l > r) ? printf("%lld\n", l - r) : printf("%lld\n", r - l);
			continue;
		}
		int cnt = 0;
		while (l != r) {
			while (l > r) {
				cnt++;
				l = check(l);
			}
			while (l < r) {
				cnt++;
				r = check(r);
			}	
		}
		printf("%d\n", cnt);
	}
	return 0;
}