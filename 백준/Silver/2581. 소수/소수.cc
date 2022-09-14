#include <iostream>
#define N 10005

using namespace std;

int prime[N];

int main()
{
	int n, m;
	int sum = 0;
	cin >> m >> n;
	for (int i = 2; i <= n / 2 + 1; i++) {
		for (int j = 2; i*j <= n; j++) {
			prime[i*j] = 1;
		}
	}
	prime[1] = 1;
	for (int i = m; i <= n; i++) {
		if (prime[i] == 0) {
			sum += i;
		}
	}
	if (sum != 0) {
		cout << sum << endl;
		for (int i = m;; i++) {
			if (prime[i] == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	else {
		cout << "-1" << endl;
	}
	return 0;
}