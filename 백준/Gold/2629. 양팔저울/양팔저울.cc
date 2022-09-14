#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 35;
const int M = 40005;

bool flag = false;

bool visit[N][M] = {};

vector < int > v;

void f_scale(int idx, int sum) {
	if (visit[idx][sum]) return;
	visit[idx][sum] = true;
	if (idx >= v.size()) return;
	
	f_scale(idx + 1, sum + v[idx]);
	f_scale(idx + 1, sum);
	f_scale(idx + 1, abs(sum - v[idx]));
}

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

	f_scale(0, 0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;
		if (visit[n][temp]) cout << "Y" << " ";
		else cout << "N" << " ";
	}
	return 0;
}