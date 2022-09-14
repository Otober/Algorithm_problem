#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, c;
long long ans = 0;

vector < long long > v;
vector < long long > g1, g2;

void f_dfs(int s, int e, vector < long long >& ve, long long sum) {
	if (s > e) {
		ve.push_back(sum);
		return;
	}
	else {
		f_dfs(s + 1, e, ve, sum);
		f_dfs(s + 1, e, ve, sum + v[s]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	f_dfs(0, n / 2 - 1, g1, 0);
	f_dfs(n / 2, n - 1, g2, 0);
	sort(g2.begin(), g2.end());
	for (int i = 0; i < g1.size(); i++) {
		ans += upper_bound(g2.begin(), g2.end(), c - g1[i]) - g2.begin();
	}
	cout << ans;
	return 0;
}