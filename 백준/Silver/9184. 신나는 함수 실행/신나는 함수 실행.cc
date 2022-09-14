#include <iostream>

using namespace std;

const int N = 25;

int cache[N][N][N] = {};

void f_initialize() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cache[i][j][k] = 0;
			}
		}
	}
}

int f_recursive(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return f_recursive(20, 20, 20);

	int& result = cache[a][b][c];
	if (result != 0) return result;

	if ((a < b) && (b < c)) result = f_recursive(a, b, c - 1) + f_recursive(a, b - 1, c - 1) - f_recursive(a, b - 1, c);
	else result = f_recursive(a - 1, b, c) + f_recursive(a - 1, b - 1, c) + f_recursive(a - 1, b, c - 1) - f_recursive(a - 1, b - 1, c - 1);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		f_initialize();
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		cout << f_recursive(a, b, c) << "\n";
	}
	return 0;
}