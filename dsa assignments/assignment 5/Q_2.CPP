#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head=NULL;

void insertEnd(int x) {
    Node* t=new Node;
    t->data=x;
    t->next=NULL;
    if(head==NULL){ head=t; return; }
    Node* p=head;
    while(p->next!=NULL) p=p->next;
    p->next=t;
}

void display() {
    Node* p=head;
    while(p!=NULL){ cout<<p->data; if(p->next) cout<<"->"; p=p->next; }
    cout<<endl;
}

void countDelete(int key) {
    int c=0;
    while(head!=NULL && head->data==key) {
        Node* t=head; head=head->next; delete t; c++;
    }
    Node* p=head;
    while(p!=NULL && p->next!=NULL) {
        if(p->next->data==key) {
            Node* t=p->next;
            p->next=p->next->next;
            delete t;
            c++;
        } else p=p->next;
    }
    cout<<"Count: "<<c<<endl;
}

int main() {
    insertEnd(1);insertEnd(2);insertEnd(1);
    insertEnd(2);insertEnd(1);insertEnd(3);insertEnd(1);
    int key=1;
    countDelete(key);
    display();
}