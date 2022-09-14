#include <iostream>
#define N 250000

using namespace std;

bool prime[N];

int main()
{
	for (long long int i = 2; i <= N - 1; i++) {
		prime[i] = true;
	}
	prime[1] = false;
	for (long long int i = 2; i < +N - 1; i++) {
		if (prime[i] == true) {
			for (long long int j = i * i; j <= N - 1; j += i) {
				prime[j] = false;
			}
		}
	}
	while (1) {
		int n;
		int cnt = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = n + 1; i <= n * 2; i++) {
			if (prime[i] == true) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}