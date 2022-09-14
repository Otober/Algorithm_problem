#include <iostream>
#include <string>

using namespace std;

const int N = 10005;

int a[N] = {};
int b[N] = {};
int cache[N] = {};
int result[N] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	string st;
	cin >> st;
	for (int i = N - st.size(); i < N; i++) {
		a[i] = st[i - (N - st.size())] - '0';
	}
	cin >> st;
	for (int i = N - st.size(); i < N; i++) {
		b[i] = st[i - (N - st.size())] - '0';
	}
	
	for (int i = N - 1; i > 0; i--) {
		int temp = a[i] + b[i] + cache[i];
		cache[i - 1] = temp / 10;
		result[i] = temp % 10;
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (result[i] != 0) flag = true;
		if (flag) cout << result[i];
	}
	return 0;
}