#include <cstdio>

using namespace std;

int main()
{
	int temp;
	int sum = 0;
	for (int i = 1; i <= 5; i++) {
		scanf("%d", &temp);
		if (temp <= 40) sum += 40;
		else sum += temp;
	}
	printf("%d", sum / 5);
	return 0;
}