#include <iostream>

using namespace std;

const int N = 31;

bool arr[N] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 28; i++) {
		int temp;
		cin >> temp;
		arr[temp] = true;
	}
	for (int i = 1; i < N; i++) {
		if (arr[i] == false) {
			cout << i << "\n";
		}
	}
	return 0;
}