#include <iostream>

using namespace std;

int main()
{
	int cnt = 0;
	int t_max = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		cnt -= a;
		cnt += b;
		if (cnt > t_max) {
			t_max = cnt;
		}
	}
	cout << t_max << endl;
	return 0;
}