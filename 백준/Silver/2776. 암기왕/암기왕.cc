#include <cstdio>
#include <algorithm>
#define N 1000005

using namespace std;

int n, m;
int book[N];

void find(int node)
{
	int s = 1, e = n;
	while (s <= e) {
		int m = (s + e) / 2;
		if (book[m] == node) {
			printf("1\n");
			return;
		}
		else {
			if (book[m] > node) {
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
	int t;
	scanf("%d", &t);
	while (t > 0) {
		t--;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &book[i]);
		}
		sort(book + 1, book + 1 + n);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int node;
			scanf("%d", &node);
			find(node);
		}
	}
	return 0;
}