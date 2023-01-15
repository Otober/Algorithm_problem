#include <iostream>
#include <string>

using namespace std;

const int N = 5005;
const int devive = 1000000;

int dp[N] = {};
int arr[N] = {};

int main() {
	string st;
	cin >> st;
	for (int i = 1; i <= st.size(); i++) {
		arr[i] = st[i - 1] - '0';
	}
	dp[0] = 1;
	for (int i = 1; i <= st.size(); i++) {
		if (arr[i] >= 1 && arr[i] <= 9) dp[i] = (dp[i] + dp[i - 1]) % devive;
		if (i == 1) continue;
		int temp = arr[i - 1] * 10 + arr[i];
		if (temp >= 10 && temp <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % devive;
		}
	}
	cout << dp[st.size()];
	return 0;
}