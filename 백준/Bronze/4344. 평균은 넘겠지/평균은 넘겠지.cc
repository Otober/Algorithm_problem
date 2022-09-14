#include <cstdio>
#define N 1005

using namespace std;

int main()
{
	int c, n;
	int dy[N];
	scanf("%d", &c);
	for (int i = 1; i <= c; i++) {
		int sum = 0,cnt=0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &dy[j]);
			sum += dy[j];
		}
		sum = sum / n;
		for (int j = 1; j <= n; j++) {
			if (dy[j] > sum) cnt++;
		}
		printf("%.3f%%\n", (float)cnt / (float)n * 100);
	}
}