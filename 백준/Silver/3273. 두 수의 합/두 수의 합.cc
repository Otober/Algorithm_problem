#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < int > v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> m;
	sort(v.begin(), v.end());
	
	int ans = 0;
	int s = 0, e = n - 1;
	while (s < e) {
		if (v[s] + v[e] == m) {
			ans++;
			s++;
			e--;
		}
		else if (v[s] + v[e] > m) e--;
		else if (v[s] + v[e] < m) s++;
	}
	cout << ans;
	return 0;
}