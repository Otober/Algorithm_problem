#include <iostream>

using namespace std;

const int N = 1000000;

bool prime[N];

int main()
{
	long long int m,n;
	cin >> m >> n;
	for (long long int i = 2; i <= n; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	for (long long int i = 2; i < +n; i++) {
		if (prime[i] == true) {
			for (long long int j = i * i; j <= n; j+=i) {
				prime[j] = false;
			}
		}
	}
	for (long long int i = m; i <= n; i++) {
		if (prime[i] == true) cout << i << "\n";
	}
	return 0;
}
