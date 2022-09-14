#include <cstdio>
#include <algorithm>
#define N 1005

using namespace std;

int Data[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &Data[i]);
	}
	sort(Data + 1, Data + 1 + n);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", Data[i]);
	}
	return 0;
}