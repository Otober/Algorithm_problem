#include <iostream>

using namespace std;

int main()
{
	int n;
	int cnt = 0;
	int sum = 0;
	int temp = 64;
	cin >> n;
	while (sum!=n) {
		if (temp + sum <= n) {
			sum += temp;
			cnt++;
		}
		temp /= 2;
	}
	cout << cnt << endl;
	return 0;
}