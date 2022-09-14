#include <cstdio>
#include <algorithm>
#define N 100005

using namespace std;

int Data[N];
int n;

void search(int node)
{
	int s = 1, e = n;
	while (s <= e) {
		int m = (s + e) / 2;
		if (Data[m] == node) {
			printf("1\n");
			return;
		}
		else {
			if (Data[m] > node) {
				e = m - 1;
			}
			else {
				s = m + 1;
			}
		}
	}
	printf("0\n");
	return;
}

int main()
{
	int m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &Data[i]);
	}
	sort(Data + 1, Data + 1 + n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int node;
		scanf("%d", &node);
		search(node);
	}
	return 0;
}