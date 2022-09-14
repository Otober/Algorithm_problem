#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long int arr[100005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int temp;
		cin >> temp;
		while (temp > 0) {
			arr[i] *= 10;
			arr[i] += temp % 10;
			temp /= 10;
		}
		if (arr[i] == 0) {
			i--;
			n--;
		}
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}