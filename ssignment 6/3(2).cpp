#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int sizeCLL(Node* head) {
    if (!head) return 0;
    int c = 0;
    Node* t = head;
    do {
        c++;
        t = t->next;
    } while (t != head);
    return c;
}

int main() {
    Node* a = new Node{10, NULL};
    Node* b = new Node{20, NULL};
    Node* c = new Node{30, NULL};
    a->next = b; b->next = c; c->next = a;
    cout << sizeCLL(a);
}