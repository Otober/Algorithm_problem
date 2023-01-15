#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 55;

int n, m;

int answer = 987654321;

bool visit[N] = {};

vector < pair < int, int > > combination;

vector < pair < int, int > > house, chicken;

void f_check() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int tmin = 987654321;
		for (int j = 0; j < combination.size(); j++) {
			int temp = abs(house[i].first - combination[j].first) + abs(house[i].second - combination[j].second);
			if (tmin > temp) tmin = temp;
		}
		sum += tmin;
	}
	if (answer > sum) answer = sum;
}

void f_combination(int next) {
	if (combination.size() == m) {
		f_check();
		return;
	}
	for (int i = next; i < chicken.size(); i++) {
		combination.push_back(chicken[i]);
		f_combination(i + 1);
		combination.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 1) house.push_back(make_pair(i, j));
			else if (temp == 2) chicken.push_back(make_pair(i, j));
		}
	}
	vector < int > combination;
	f_combination(0);
	cout << answer;
	return 0;
}