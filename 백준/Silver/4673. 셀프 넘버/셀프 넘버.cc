#include <cstdio>
#define N 10005

using namespace std;

int visit[N];

int main()
{
	for (int i = 1; i <= 10000; i++) {
		int node = i;
		int need = i;
		while (node > 0) {
			need += node % 10;
			node /= 10;
		}
		visit[need] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (visit[i] == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}