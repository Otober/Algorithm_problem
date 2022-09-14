#include <iostream>
#include <algorithm>
#define N 9

using namespace std;

int height[N];

int main()
{
	int sum = 0;
	bool flag = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	sort(height, height + N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sum - height[i] - height[j] == 100) {
				flag = 1;
				for (int k = 0; k < N; k++) {
					if (k == i || k == j) continue;
					cout << height[k] << endl;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}
	return 0;
}