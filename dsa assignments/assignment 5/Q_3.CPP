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

void middle() {
    Node* slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}

int main() {
    for(int i=1;i<=5;i++) insertEnd(i);
    middle();
}