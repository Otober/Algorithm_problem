#include <iostream>

using namespace std;

const long long devive = 1000000007;

long long n;

struct Matrix {
	long long data[2][2] = {};
};

Matrix f_multiply(Matrix a, Matrix b) {
	Matrix ans;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans.data[i][j] += (a.data[k][j] * b.data[i][k]) % devive;
				ans.data[i][j] %= devive;
			}
		}
	}
	return ans;
}

Matrix f_devive(Matrix temp, long long x) {
	if (x > 1) {
		temp = f_devive(temp, x / 2);
		temp = f_multiply(temp, temp);
		if (x % 2 == 1) {
			Matrix t;
			t.data[0][0] = 1; t.data[0][1] = 1;
			t.data[1][0] = 1; t.data[1][1] = 0;
			temp = f_multiply(temp, t);
 		}
	}
	return temp;
}

long long f_fibonacci(long long x) {
	Matrix temp;
	temp.data[0][0] = 1; temp.data[0][1] = 1;
	temp.data[1][0] = 1; temp.data[1][1] = 0;
	temp = f_devive(temp, x);
	return temp.data[0][1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	if (n == 0) cout << "0" << endl;
	else cout << f_fibonacci(n) << endl;
	return 0;
}