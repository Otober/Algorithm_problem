#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque <int>pq;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string st;
		int temp;
		cin >> st;
		if (st == "push_back") {
			cin >> temp ;
			pq.push_back(temp);
		}
		else if (st == "push_front") {
			cin >> temp ;
			pq.push_front(temp);
		}
		else if (st == "pop_front") {
			if (pq.empty()==1) {
				cout << "-1" << endl;
			}
			else {
				cout << pq.front() << endl;
				pq.pop_front();
			}
		}
		else if (st == "pop_back") {
			if (pq.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << pq.back() << endl;
				pq.pop_back();
			}
		}
		else if (st == "size") {
			cout << pq.size() << endl;
		}
		else if (st == "empty") {
			cout << pq.empty() << endl;
		}
		else if (st == "front") {
			if (pq.empty()) {
				cout << "-1" << endl;
			}
			else cout << pq.front() << endl;
		}
		else if (st == "back") {
			if (pq.empty()) {
				cout << "-1" << endl;
			}
			else cout << pq.back() << endl;
		}
	}
	return 0;
}