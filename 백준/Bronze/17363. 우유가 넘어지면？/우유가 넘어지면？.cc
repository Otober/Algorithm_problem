#include <iostream>

using namespace std;

const int N = 105;

char arr[N][N] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			switch (arr[j][i]) {
			case '.':
				cout << ".";
				break;
			case 'O':
				cout << "O";
				break;
			case '-':
				cout << "|";
				break;
			case '|':
				cout << "-";
				break;
			case '/':
				cout << "\\";
				break;
			case '\\':
				cout << '/';
				break;
			case '^':
				cout << "<";
				break;
			case '<':
				cout << "v";
				break;
			case 'v':
				cout << ">";
				break;
			case '>':
				cout << "^";
				break;
			default:
				//cout << "\n";
				break;
			}
		}
		cout << "\n";
	}
}

