#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node{20, NULL};
    Node* n1 = new Node{100, NULL};
    Node* n2 = new Node{40, NULL};
    Node* n3 = new Node{80, NULL};
    Node* n4 = new Node{60, NULL};

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = head;

    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data;
}