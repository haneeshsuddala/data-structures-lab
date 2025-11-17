#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertFirst(int x) {
    Node* n = new Node;
    n->data = x;
    if (!head) {
        head = n;
        n->next = head;
    } else {
        Node* t = head;
        while (t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    }
}

void insertLast(int x) {
    Node* n = new Node;
    n->data = x;
    if (!head) {
        head = n;
        n->next = head;
    } else {
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
}

void insertAfter(int key, int x) {
    if (!head) return;
    Node* t = head;
    do {
        if (t->data == key) {
            Node* n = new Node;
            n->data = x;
            n->next = t->next;
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
}

void deleteNode(int key) {
    if (!head) return;
    Node *t = head, *p = NULL;
    do {
        if (t->data == key) {
            if (t == head) {
                Node* last = head;
                while (last->next != head) last = last->next;
                if (head == head->next) {
                    delete head;
                    head = NULL;
                    return;
                }
                head = head->next;
                last->next = head;
                delete t;
                return;
            }
            p->next = t->next;
            delete t;
            return;
        }
        p = t;
        t = t->next;
    } while (t != head);
}

void searchNode(int key) {
    if (!head) {
        cout << "Not Found\n";
        return;
    }
    Node* t = head;
    do {
        if (t->data == key) {
            cout << "Found\n";
            return;
        }
        t = t->next;
    } while (t != head);
    cout << "Not Found\n";
}

void display() {
    if (!head) return;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
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