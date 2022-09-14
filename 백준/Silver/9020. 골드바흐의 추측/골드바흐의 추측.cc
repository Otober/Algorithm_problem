#include <iostream>

using namespace std;

const int N = 10005;
bool prime[N];

bool check(bool a, bool b, int n)
{
	if (a == false) return 0;
	if (b == false) return 0;
	return 1;
}

int main()
{
	for (long long int i = 2; i <= N; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	for (long long int i = 2; i < N; i++) {
		if (prime[i] == true) {
			for (long long int j = i * i; j < N; j += i) {
				prime[j] = false;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a = 0, b = N;
		for (int i = 1; i <= n / 2; i++) {
			if (check(prime[i], prime[n - i], n)) {
				if (n - 2 * i < b - a) {
					a = i;
					b = n - i;
				}
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}