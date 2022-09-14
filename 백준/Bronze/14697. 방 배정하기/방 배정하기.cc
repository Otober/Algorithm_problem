#include <cstdio>

int main()
{
	int n, a, b, c;
	int node = 1;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	for (int i = 0;; i++) {
		if (node == 0) break;
		if (a*i > n) {
			printf("0");
			break;
		}
		for (int j = 0;; j++) {
			if (node == 0) break;
			if (j*b > n) break;
			for (int k = 0;; k++) {
				if (a*i + b * j + c * k == n) {
					printf("1");
					node = 0;
					break;
				}
				if (k*c > n) break;
			}
		}
	}
	return 0;
}