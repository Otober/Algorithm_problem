#include <iostream>
#define N 100005
#define Word_N 81
#define Alphabats 26

using namespace std;

int char_to_int(char c) {
    return c - 'a';
}

bool initial;
int ans;
char arr[N][Word_N];

struct Trie_Node{
    Trie_Node *child[Alphabats];
    bool terminal;
    int cnt;
    
    Trie_Node() {
        for(int i = 0; i < Alphabats; i++) {
            child[i] = NULL;
        }
        terminal = false;
        cnt = 0;
    }
    
    ~Trie_Node() {
        for(int i = 0; i < Alphabats; i++) {
            if(child[i] != NULL) delete child[i];
        }
    }
    
    void insert(char *word) {
        if(*word == 0) {
            terminal = true;
            return;
        }
        int next = char_to_int(*word);
        if(child[next] == NULL) {
            child[next] = new Trie_Node;
            cnt++;
        }
        child[next] -> insert(word + 1);
    }
    
    void find(char *word) {
        if(*word == 0) return;
        
        if(initial) {
            initial = false;
            ans++;
        }
        else {
            if(terminal) ans++;
            else if(cnt > 1) ans++;
        }
        int next = char_to_int(*word);
        child[next] -> find(word + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed;
    cout.precision(2);
    
    int n;
    while(cin >> n) {
        Trie_Node *root = new Trie_Node;
        ans = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            root -> insert(arr[i]);
        }
        for(int i = 0; i < n; i++) {
            initial = true;
            root -> find(arr[i]);
        }
        cout << (double)ans / (double)n << "\n";
        delete root;
    }
    return 0;
}