#include <iostream>

using namespace std;

const int N = 105;

int arr[N] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		int temp;
		cin >> a >> b;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}