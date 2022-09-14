#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node {
    map < string, Node > child;
}root;

void insert(Node &node, vector < string > &v, int idx) {
    if(idx == v.size()) return;
    
    if(!node.child.count(v[idx])) node.child[v[idx]] = Node();
    insert(node.child[v[idx]], v, idx + 1);
}

void print(Node &node, int dep) {
    for(auto i : node.child) {
        for(int j = 0; j < dep; j++) {
            cout << "--";
        }
        cout << i.first << "\n";
        print(i.second, dep + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        vector < string > v(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
        }
        insert(root, v, 0);
    }
    print(root, 0);
    return 0;
}