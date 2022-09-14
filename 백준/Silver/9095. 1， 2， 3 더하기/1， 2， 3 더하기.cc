#include <cstdio>
#define N 15

using namespace std;

int dy[N];

int main()
{
	int t, n;
	scanf("%d", &t);
	dy[0] = 1;
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 0; j <= n; j++) {
			if (dy[j] == 0) {
				if (j >= 1) dy[j] += dy[j - 1];
				if (j >= 2) dy[j] += dy[j - 2];
				if (j >= 3) dy[j] += dy[j - 3];
			}
		}
		printf("%d\n", dy[n]);
	}
	return 0;
}