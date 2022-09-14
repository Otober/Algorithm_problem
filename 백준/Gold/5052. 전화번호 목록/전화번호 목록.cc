#include <iostream>
#include <algorithm>
#define N 15

using namespace std;

const int TrieNode = 10;

struct Trie {
    Trie *child[TrieNode];
    bool finish;
    bool nextchild;
    
    Trie() {
        //fill_n(child, TrieNode, NULL);
        for(int i = 0; i < TrieNode; i++) {
            child[i] = NULL;
        }
        finish = false;
        nextchild = false;
    }
    ~Trie() {
        for(int i = 0; i < TrieNode; i++) {
            if(child[i] != NULL) delete child[i];
        }
    }
    
    bool insert(const char *key) {
        if(*key == '\0') {
            finish = true;
            if(nextchild) return false;
            else return true;
        }
        
        int nextkey = *key - '0';
        if(!child[nextkey]) child[nextkey] = new Trie;
        
        nextchild = true;
        
        bool flag = child[nextkey] -> insert(key + 1);
        return !finish && flag;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        Trie *root = new Trie;
        int n;
        cin >> n;
        
        bool flag = true;
        for(int i = 0; i < n; i++) {
            char phone_numer[N];
            cin >> phone_numer;
            if(flag && root -> insert(phone_numer) == false) {
                flag = false;
            }
        }
        
        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        delete root;
    }
    return 0;
}