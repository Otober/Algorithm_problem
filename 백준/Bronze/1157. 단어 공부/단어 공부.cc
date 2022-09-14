#include <cstdio>
#define N 1000005

using namespace std;

char data[N];
int cnt[N];

int main()
{
	scanf("%s", data);
	int i = 0;
	int temp = 0;
	int tcnt = 0;
	while (data[i] != NULL) {
		if ('A' <= data[i] && data[i] <= 'Z') {
			cnt[data[i]]++;
			if (temp < cnt[data[i]]) temp = cnt[data[i]];
		}
		else {
			cnt[data[i] - 'a' + 'A']++;
			if (temp < cnt[data[i] - 'a' + 'A']) temp = cnt[data[i] - 'a' + 'A'];
		}
		i++;
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		if (cnt[i] == temp) tcnt++;
	}
	if (tcnt == 1) {
		for (int i = 'A'; i <= 'Z'; i++) {
			if (temp == cnt[i]) {
				printf("%c", i);
				break;
			}
		}
	}
	else {
		printf("?");
	}
	return 0;
}
