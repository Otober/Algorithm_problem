#include <cstdio>
#include <limits.h>
#define N 1000005

using namespace std;

int data[N];

void check(int temp, int node) {
	if (data[temp] > data[node] + 1) {
		data[temp] = data[node] + 1;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n; i >= 1; i--) {
		data[i] = INT_MAX;
	}
	data[n] = 0;
	for (int i = n; i >= 1; i--) {
		if (data[i] != -1) {
			if (i % 3 == 0) {
				check(i / 3, i);
			}
			if (i % 2 == 0) {
				check(i / 2, i);
			}
			check(i - 1, i);
		}
	}
	printf("%d", data[1]);
	return 0;
}