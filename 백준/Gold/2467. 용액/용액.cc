#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector < int > v;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int left = 0, right = v.size() - 1;
	int l_answer = 0, r_answer = v.size() - 1;
	int temp_answer = abs(v[l_answer] + v[r_answer]);
	while (left < right) {
		int temp = v[left] + v[right];
		if (temp_answer > abs(temp)) {
			l_answer = left;
			r_answer = right;
			temp_answer = abs(temp);
		}
		if (temp > 0) right--;
		else if (temp < 0) left++;
		else break;
	}
	cout << v[l_answer] << " " << v[r_answer];
	return 0;
}