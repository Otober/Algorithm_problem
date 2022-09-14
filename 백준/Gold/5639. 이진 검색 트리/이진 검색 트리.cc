#include <iostream>
#define N 10005

using namespace std;

struct Node {
    int data, depth;
    Node *left, *right;
    
    Node(int _data) 
        :data(_data), depth(0), left(NULL), right(NULL)
    {}
    
    void setLeft(Node *node) {
        left = node;
    }
    void setRight(Node *node) {
        right = node;
    }
};


Node* insert(Node *root, Node *node) {
    if(root == NULL) return node;
    if(node -> data < root -> data) 
        root -> setLeft(insert(root -> left, node));
    else 
        root -> setRight(insert(root -> right, node));
    return root;
}

void f_print(Node *node) {
    if(node == NULL) return;
    f_print(node -> left);
    f_print(node -> right);
    cout << node -> data << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;
    Node *node = NULL;
    while(cin >> num) {
        node = insert(node, new Node(num));
    } 
    f_print(node);
    return 0;
}