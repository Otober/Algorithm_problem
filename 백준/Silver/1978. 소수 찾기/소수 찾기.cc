#include <cstdio>
#define N 1005

int data[N];

int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	while (n > 0) {
		n--;
		int temp;
		int flag = 1;
		scanf("%d", &temp);
		if (temp == 1) continue;
		for (int i = 2; i <= temp / 2; i++) {
			if (temp%i == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}