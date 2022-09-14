#include <iostream>

using namespace std;

const int N = 4;

pair < long long, long long > arr[N];

int f_ccw(pair < long long, long long > a, pair < long long, long long > b, pair < long long, long long > c) {
	long long temp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
	temp -= (a.first * c.second) + (b.first * a.second) + (c.first * b.second);
	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

bool f_check(pair < long long, long long >& a, pair < long long, long long >& b, pair < long long, long long >& c, pair < long long, long long >& d) {
	long long abc = f_ccw(a, b, c);
	long long abd = f_ccw(a, b, d);
	long long cda = f_ccw(c, d, a);
	long long cdb = f_ccw(c, d, b);
	if ((abc * abd == 0) && (cda * cdb == 0)) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && c <= b) return true;
		else return false;
	}
	if ((abc * abd <= 0) && (cda * cdb <= 0)) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < N; i++) {
		long long a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}

	if (f_check(arr[0], arr[1], arr[2], arr[3])) cout << 1;
	else cout << 0;
	return 0;
}