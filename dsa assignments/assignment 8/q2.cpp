#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* n = new Node();
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insertNode(root->left, value);
    else root->right = insertNode(root->right, value);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* current = searchNonRecursive(root, key);
    if (current == NULL) return NULL;
    if (current->right) return findMin(current->right);
    Node* successor = NULL;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* current = searchNonRecursive(root, key);
    if (current == NULL) return NULL;
    if (current->left) return findMax(current->left);
    Node* predecessor = NULL;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    int key = 40;

    Node* r1 = searchRecursive(root, key);
    Node* r2 = searchNonRecursive(root, key);
    Node* mn = findMin(root);
    Node* mx = findMax(root);
    Node* succ = inorderSuccessor(root, key);
    Node* pred = inorderPredecessor(root, key);

    cout << "Search Recursive: " << (r1 ? "Found" : "Not Found") << endl;
    cout << "Search Non-Recursive: " << (r2 ? "Found" : "Not Found") << endl;
    cout << "Minimum: " << mn->data << endl;
    cout << "Maximum: " << mx->data << endl;

    if (succ) cout << "Inorder Successor of " << key << ": " << succ->data << endl;
    else cout << "No Successor" << endl;

    if (pred) cout << "Inorder Predecessor of " << key << ": " << pred->data << endl;
    else cout << "No Predecessor" << endl;

    return 0;
}