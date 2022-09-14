#include <iostream>
#define N 105

using namespace std;

int arr[N] = {};
bool visit[N] = {};
bool ans[N] = {};

bool dfs(int node) {
	int temp = node;
	if (node == arr[node]) return true;
	while (visit[temp] == false) {
		visit[temp] = true;
		temp = arr[temp];
		if (temp == node) return true;
	}
	return false;

}

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (dfs(i)) {
			int temp = i;
			while (ans[temp]==false) {
				cnt++;
				ans[temp] = true;
				temp = arr[temp];
			}
		}
		for (int i = 1; i <= n; i++) {
			visit[i] = false;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i]) {
			cout << i << endl;
		}
	}
}