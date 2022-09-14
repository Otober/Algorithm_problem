#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int ans = 0;
	int n, r, c;
	cin >> n >> r >> c;
    int y = pow(2, n) / 2;
    int x = pow(2, n) / 2;

    while (n-- > 0) {
        int temp = pow(2, n) / 2;
        int skip = pow(4, n);

        if (r < y && c < x) {
            x -= temp;
            y -= temp;
        }
        else if (r < y && x <= c) {
            x += temp;
            y -= temp;
            ans += skip;
        }
        else if (y <= r && c < x) {
            x -= temp;
            y += temp;
            ans += skip * 2;
        }
        else {
            x += temp;
            y += temp;
            ans += skip * 3;
        }
    }
    cout << ans;
	return 0;
}