#include <cstdio>
#define N 100

char str[N];

int main()
{
	int n;
	scanf("%d", &n);
	while (n > 0) {
		int i = 0;
		int sum = 0;
		int cnt = 0;
		n--;
		scanf("%s", &str);
		while (str[i] != NULL) {
			if (str[i] == 'O') {
				cnt++;
				sum += cnt;
			}
			else if(str[i]=='X'){
				cnt = 0;
			}
			else break;
			i++;
		}
		printf("%d\n", sum);
		for (int j = 0;j <= i; j++) {
			str[j] = 0;
		}
	}
	return 0;
}