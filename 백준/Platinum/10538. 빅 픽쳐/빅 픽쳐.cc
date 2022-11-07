#include <iostream>
#include <map>
#include <queue>
#include <map>

using namespace std;

const int N = 2002;

vector < bool > p[N], m[N];

map < vector < bool >, int > word;

struct Trie {
	Trie* next[2], * fail;
	int terminal;

	Trie() {
		next[0] = next[1] = NULL;
		terminal = -1;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) {
			if (next[i]) delete next[i];
		}
	}

	void f_insert(vector < bool > &key, int pos, int k) {
		if (pos == key.size()) {
			terminal = k;
			return;
		}
		int nnext = key[pos];
		if (!next[nnext]) {
			next[nnext] = new Trie;
		}
		next[nnext]->f_insert(key, pos + 1, k);
	}

	void f_travel_terminal(Trie* now, int k) {
	    if (now == NULL) return;
	    else cout << now->terminal << " ";
	    for (int i = 0; i < 2; i++) {
	    	f_travel_terminal(now->next[i], i);
	    }
	}
	void f_travel_k(Trie* now, int k) {
	    if (now == NULL) return;
	    else cout << k << " ";
	    for (int i = 0; i < 2; i++) {
	        f_travel_k(now->next[i], i);
	    }
	}
};

void f_Trie_fail(Trie* root) {
	queue < Trie* > q;
	root->fail = root;
	q.push(root);

	while (!q.empty()) {
		Trie* now = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			Trie* nnext = now->next[i];
			if (nnext == NULL) continue;

			if (now == root) nnext->fail = root;
			else {
				Trie* dest = now->fail;
				while (dest != root && !dest->next[i]) {
					dest = dest->fail;
				}
				if (dest->next[i]) dest = dest->next[i];
				nnext->fail = dest;
			}
			if (nnext->fail->terminal != -1) nnext->terminal = nnext->fail->terminal;
			q.push(nnext);
		}
	}
}

int main() {
	int hp, wp, hm, wm;
	cin >> hp >> wp >> hm >> wm;
	for (int i = 0; i < hp; i++) {
		for (int j = 0; j < wp; j++) {
			char temp;
			cin >> temp;
			if (temp == 'o') p[i].push_back(true);
			else p[i].push_back(false);
		}
	}
	for (int i = 0; i < hm; i++) {
		for (int j = 0; j < wm; j++) {
			char temp;
			cin >> temp;
			if (temp == 'o') m[i].push_back(true);
			else m[i].push_back(false);
		}
	}

	vector < int > tkmp;
	for (int i = 0; i < hp; i++) {
		map < vector < bool >, int >::iterator iter = word.find(p[i]);
		if (iter == word.end()) {
			word.insert(make_pair(p[i], i));
			tkmp.push_back(i);
		}
		else tkmp.push_back(iter->second);
	}

	Trie* root = new Trie;
	for (int i = 0; i < hp; i++) {
		if (tkmp[i] == i) root->f_insert(p[i], 0, i);
	}
	f_Trie_fail(root);

	vector < vector < int > > check(hm, vector < int >(wm, -1));

	for (int i = 0; i < hm; i++) {
		Trie* current = root;
		for (int j = 0; j < wm; j++) {
			bool nnext = m[i][j];
			while (current != root && !current->next[nnext]) {
				current = current->fail;
			}
			if (current->next[nnext]) {
				current = current->next[nnext];
			}
			if (current->terminal != -1) {
				check[i][j] = current->terminal;
			}
		}
	}


	vector < int > pi(hp, 0);
	int k = 0;
	for (int i = 1; i < hp; i++) {
		while (k > 0 && tkmp[i] != tkmp[k]) {
			k = pi[k - 1];
		}
		if (tkmp[i] == tkmp[k]) pi[i] = ++k;
	}

	vector < pair < int, int > > answer;
	for (int j = 0; j < wm; j++) {
		k = 0;
		for (int i = 0; i < hm; i++) {
			while (k > 0 && check[i][j] != tkmp[k]) {
				k = pi[k - 1];
			}
			if (check[i][j] == tkmp[k]) {
				if (k == hp - 1) {
					answer.push_back(make_pair(i, j));
					k = pi[k];
				}
				else k++;
			}
		}
	}
	cout << answer.size();
}