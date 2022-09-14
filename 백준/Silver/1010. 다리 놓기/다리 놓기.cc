#include <iostream>

using namespace std;

const int N = 35;

int cache[N][N] = {};

void f_initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cache[i][j] = 0;
		}
	}
}

long long f_combination(int n, int r) {
	if (n == r || r == 0) return 1;
	int& result = cache[n][r];
	if (result == 0) result = f_combination(n - 1, r - 1) + f_combination(n - 1, r);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		long long ans = 1;
		f_initialize();
		cin >> n >> m;
		cout << f_combination(m, n) << "\n";
	}
	return 0;
}