#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

stack <int>adj;

int main() {
	int n;
	char std[1000];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &std);
		if (strcmp(std,"push") == 0) {
			int node;
			scanf("%d\n", &node);
			adj.push(node);
		}
		else if (strcmp(std,"top") == 0) {
			if (adj.empty()) {
				printf("-1\n");
			}
			else printf("%d\n", adj.top());
		}
		else if (strcmp(std, "size") == 0) {
			printf("%d\n", adj.size());
		}
		else if (strcmp(std, "empty") == 0) {
			printf("%d\n", adj.empty());
		}
		else if (strcmp(std, "pop") == 0) {
			if (adj.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", adj.top());
				adj.pop();
			}
		}
	}
	return 0;
}
