#include <cstdio>

using namespace std;

int main()
{
	int n,cnt=0;
	int c;
	scanf("%d", &n);
	c = n;
	while (1) {
		cnt++;
		int a = 0, b = 0;
		b = n % 10;
		a = n / 10;
		if (a + b < 10) n = b * 10 + a + b;
		else {
			n = b * 10 + (a + b) % 10;
		}
		if (c == n) {
			printf("%d", cnt);
			break;
		}
	}
}