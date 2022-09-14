#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 2000000005;

vector < int > v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int sum = MAX;
	int ans[2] = {};
	int s = 0, e = n - 1;
	while (s < e) {
		if (sum > abs(v[s] + v[e])) {
			sum = abs(v[s] + v[e]);
			ans[0] = v[s], ans[1] = v[e];
		}
		if (v[s] + v[e] < 0) s++;
		else e--;
	}
	cout << ans[0] << " " << ans[1];
	return 0;
}