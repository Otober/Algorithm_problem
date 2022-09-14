#include <cstdio>

using namespace std;

int main() {
	int n,sum=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%1d", &temp);
		sum += temp;
	}
	printf("%d", sum);
	return 0;
}
