#include <cstdio>
#define N 1005

using namespace std;

int main()
{
	float dy[N];
	int n,m=0;
	float sum=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%f", &dy[i]);
		if (dy[i] > m) m = dy[i];
	}
	for (int i = 1; i <= n ; i++) {
		dy[i] = dy[i] / m * 100;
		sum += dy[i];
	}
	printf("%.2f", sum / n);
}