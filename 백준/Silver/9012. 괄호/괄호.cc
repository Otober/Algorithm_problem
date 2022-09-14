#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

stack <int>adj;

int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		while (1) {
			char node;
			scanf("%c", &node);
			if (node == '\n') {
				if (adj.empty()) {
					if (temp == -1) printf("NO\n");
					else printf("YES\n");
				}
				else printf("NO\n");
				while (!adj.empty()) {
					adj.pop();
				}
				break;
			}
			else {
				if (node == '(') {
					adj.push(1);
				}
				else {
					if (adj.empty()) {
						temp = -1;
					}
					else adj.pop();
				}
			}
		}
	}
	return 0;
}
