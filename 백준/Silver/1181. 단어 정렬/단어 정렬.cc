#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20005

using namespace std;

struct A {
	int	len;
	char st[51];
	bool operator()(A i, A j)
	{
		if (i.len != j.len) return i.len < j.len;
		for (int k = 0; k < i.len; k++) {
			if (i.st[k] != j.st[k]) return i.st[k] < j.st[k];
		}
		return 0;
	}
}word[N];

bool same(int node)
{
	if (word[node].len != word[node-1].len) return 1;
	else {
		for (int i = 0; i < word[node].len; i++) {
			if (word[node].st[i] != word[node - 1].st[i]) return 1;
		}
		return 0;
	}
}

int main()
{
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", word[i].st);
		word[i].len = strlen(word[i].st);
	}
	sort(word + 1, word + 1 + n, A());
	for (int i = 1; i <= n; i++) {
		if (same(i)) printf("%s\n", word[i].st);
	}
	return 0;
}
