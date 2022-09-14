#include <cstdio>

using namespace std;

int main() {
	char a;
	int cnt = 0;
	a = getchar();

	while (a != -1) {
		cnt++;
		putchar(a);
		a = getchar();
		if(cnt==10) {
			cnt = 0;
			printf("\n");
		}
	}

	return 0;
}
