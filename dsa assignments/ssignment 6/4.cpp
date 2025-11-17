#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* t = head;
    while (t->next) t = t->next;
    Node* left = head;
    Node* right = t;
    while (left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* a = new Node{'r', NULL, NULL};
    Node* b = new Node{'a', a, NULL};
    Node* c = new Node{'d', b, NULL};
    a->next = b; b->next = c;
    cout << (isPalindrome(a) ? "Yes" : "No");
}