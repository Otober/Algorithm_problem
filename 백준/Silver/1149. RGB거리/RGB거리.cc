#include <cstdio>
#include <limits.h>
#include <algorithm>
#define N 1005

using namespace std;

int tdata[N][5];
int dis[N][5];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &tdata[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		dis[i][1] = min(dis[i - 1][2], dis[i - 1][3]) + tdata[i][1];
		dis[i][2] = min(dis[i - 1][3], dis[i - 1][1]) + tdata[i][2];
		dis[i][3] = min(dis[i - 1][1], dis[i - 1][2]) + tdata[i][3];
	}
	printf("%d", min(min(dis[n][1], dis[n][2]),dis[n][3]));
	return 0;
}