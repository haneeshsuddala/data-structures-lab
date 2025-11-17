#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int sizeDLL(Node* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

int main() {
    Node* a = new Node{10, NULL, NULL};
    Node* b = new Node{20, a, NULL};
    a->next = b;
    cout << sizeDLL(a);
}