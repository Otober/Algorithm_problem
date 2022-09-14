#include <cstdio>

using namespace std;

int main()
{
	int n,dy[6];
	scanf("%d", &n);
	if (n < 100) printf("%d", n);
	else {
		int sum = 99;
		for (int i = 100; i <= n; i++) {
			int node = i,cnt=0;
			for (int j = 1;; j++) {
				if (node < 1) {
					cnt = j - 1;
					break;
				}
				dy[j] = node % 10;
				node /= 10;
			}
			int temp = dy[2] - dy[1];
			int flag = 0;
			for (int j = 2; j <= cnt; j++) {
				if (dy[j] - dy[j - 1] != temp) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) sum++;
		}
		printf("%d", sum);
	}
}