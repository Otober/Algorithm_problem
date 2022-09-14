#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int bit, q;
		int a, b, c, d;
		int coin = 0;

		cin >> bit >> q >> a >> b >> c >> d;
		coin = (q / c) * d;
		bit += ((coin / b) * a);
		coin %= b;

		int answer = 0;
		int x = (bit - coin) / (a + b);
		answer = max(min(bit - a * x, coin + b * x), min(bit - a * (x + 1), coin + b * (x + 1)));
		cout << answer << "\n";
	}
	return 0;
}