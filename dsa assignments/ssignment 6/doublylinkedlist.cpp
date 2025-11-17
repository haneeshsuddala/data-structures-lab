#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertFirst(int x) {
    Node* n = new Node;
    n->data = x;
    n->prev = NULL;
    n->next = head;
    if (head) head->prev = n;
    head = n;
}

void insertLast(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (!head) {
        n->prev = NULL;
        head = n;
    } else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void insertAfter(int key, int x) {
    Node* t = head;
    while (t) {
        if (t->data == key) {
            Node* n = new Node;
            n->data = x;
            n->next = t->next;
            n->prev = t;
            if (t->next) t->next->prev = n;
            t->next = n;
            return;
        }
        t = t->next;
    }
}

void deleteNode(int key) {
    Node* t = head;
    while (t) {
        if (t->data == key) {
            if (t == head) {
                head = head->next;
                if (head) head->prev = NULL;
                delete t;
                return;
            }
            if (t->next) t->next->prev = t->prev;
            if (t->prev) t->prev->next = t->next;
            delete t;
            return;
        }
        t = t->next;
    }
}

void searchNode(int key) {
    Node* t = head;
    while (t) {
        if (t->data == key) {
            cout << "Found\n";
            return;
        }
        t = t->next;
    }
    cout << "Not Found\n";
}

void display() {
    Node* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int ch, x, key;
    while (1) {
        cin >> ch;
        if (ch == 1) { cin >> x; insertFirst(x); }
        else if (ch == 2) { cin >> x; insertLast(x); }
        else if (ch == 3) { cin >> key >> x; insertAfter(key, x); }
        else if (ch == 4) { cin >> key; deleteNode(key); }
        else if (ch == 5) { cin >> key; searchNode(key); }
        else if (ch == 6) display();
        else break;
    }
}