#include <iostream>
#include <algorithm>
#define N 1005

using namespace std;

int atm[N];

int main()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> atm[i];
	}
	sort(atm, atm + n);
	for (int i = 0; i < n; i++) {
		sum += (n - i)*atm[i];
	}
	cout << sum << endl;
	return 0;
}