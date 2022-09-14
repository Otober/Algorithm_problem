#include <iostream>
#include <stack>
#include <queue>
#define N 100005

using namespace std;

stack <int> st;
queue <char>pq;
int data_array[N];

int main()
{
	int n;
	int cnt = 1;
	int tcnt = 0;
	int flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data_array[i];
	}
	while (cnt <= n) {
		if (flag == 1) break;
		while (cnt <= data_array[tcnt]) {
			st.push(cnt++);
			pq.push('+');
		}
		while (cnt > data_array[tcnt] && st.empty() == 0) {
			int temp = st.top();
			if (temp != data_array[tcnt]) {
				flag = 1;
				cout << "NO\n";
				break;
			}
			else {
				st.pop();
				pq.push('-');
				tcnt++;
			}
		}
	}
	if (flag == 0) {
		int temp = pq.size();
		for (int i = 0; i < temp; i++) {
			cout << pq.front() << "\n";
			pq.pop();
		}
	}
	return 0;
}