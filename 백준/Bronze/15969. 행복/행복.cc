#include <iostream>
#define N 1005

using namespace std;

int arr[N] = { 0 };

int main()
{
	int tmax = -1000000;
	int tmin = 1000000;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (tmax < arr[i]) tmax = arr[i];
		if (tmin > arr[i]) tmin = arr[i];
	}
	cout << tmax - tmin << endl;
	return 0;
}