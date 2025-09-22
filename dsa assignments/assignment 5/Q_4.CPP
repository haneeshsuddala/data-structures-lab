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

void reverse() {
    Node* prev=NULL,*curr=head,*nxt=NULL;
    while(curr!=NULL) {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
}

void display() {
    Node* p=head;
    while(p!=NULL){ cout<<p->data; if(p->next) cout<<"->"; p=p->next; }
    cout<<"->NULL"<<endl;
}

int main() {
    insertEnd(1);insertEnd(2);insertEnd(3);insertEnd(4);
    reverse();
    display();
}