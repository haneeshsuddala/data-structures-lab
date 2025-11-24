#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main() {
    Node* a = new Node{1,0};
    Node* b = new Node{2,0};
    Node* c = new Node{3,0};
    Node* d = new Node{4,0};

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    unordered_set<Node*> s;
    Node* t = a;
    bool loop = false;

    while(t){
        if(s.find(t)!=s.end()){
            loop = true;
            break;
        }
        s.insert(t);
        t = t->next;
    }

    cout << (loop ? "true" : "false");
    return 0;
}