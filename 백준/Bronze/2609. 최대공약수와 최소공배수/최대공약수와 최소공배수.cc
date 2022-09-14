#include <cstdio>

using namespace std;

int cal(int a, int b)
{
	while (b>0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	int a, b, node;
	scanf("%d %d", &a, &b);
	node = cal(a, b);
	printf("%d\n", node);
	printf("%d\n", (a / node)*(b / node)*node);
	return 0;
}
