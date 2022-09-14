#include <iostream>
#define N 10005

using namespace std;

double arr[N];

int main()
{
	cout << fixed;
	cout.precision(3);

	int n;
	double tmax = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		double temp = 1.0;
		for (int j = i; j <= n; j++) {
			temp *= arr[j];
			if (tmax < temp) tmax = temp;
		}
	}
	cout << tmax << endl;
	return 0;
}