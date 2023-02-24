#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans;
	int sum = 0, n;
	cin >> ans >> n;
	for (int i = 0; i < n; i++) {
		int temp, ntemp;
		cin >> temp >> ntemp;
		sum += (temp * ntemp);
	}
	if (ans == sum) cout << "Yes";
	else cout << "No";
	return 0;
}