#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* create(int v){
    Node* n = new Node;
    n->data = v;
    n->left = n->right = 0;
    return n;
}

bool dfs(Node* r, unordered_set<int> &s){
    if(!r) return false;
    if(s.find(r->data)!=s.end()) return true;
    s.insert(r->data);
    return dfs(r->left,s) || dfs(r->right,s);
}

int main(){
    Node* root = create(5);
    root->left = create(3);
    root->right = create(7);
    root->left->left = create(3);

    unordered_set<int> s;
    bool f = dfs(root,s);

    if(f) cout << "Duplicates Found";
    else cout << "No Duplicates";

    return 0;
}