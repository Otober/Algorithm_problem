#include <cstdio>
#define N 105

char str[N];
int data[N*5];

int main()
{
	int i = 0;
	scanf("%s", &str);
	for (int j = 0; j < N*5; j++) {
		data[j] = -1;
	}
	while (str[i] != NULL) {
		if (data[str[i]] == -1) {
			data[str[i]] = i;
		}
		i++;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}