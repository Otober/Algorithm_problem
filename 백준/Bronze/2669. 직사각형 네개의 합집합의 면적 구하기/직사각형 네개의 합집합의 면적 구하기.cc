#include <iostream>
#define N 105

using namespace std;

bool arr[N][N] = {};

int main() {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				if (arr[i][j] == false) {
					arr[i][j] = true;
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}