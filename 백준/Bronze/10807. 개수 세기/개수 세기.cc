#include <iostream>

using namespace std;

const int N = 405;

int arr[N] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int v, cnt = 0;
	cin >> v;
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) cnt++;
	}
	cout << cnt;
	return 0;
}