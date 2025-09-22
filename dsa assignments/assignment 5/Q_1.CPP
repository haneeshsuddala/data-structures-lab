#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = head;
    head = t;
}

void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if(head == NULL){ head=t; return; }
    Node* p=head;
    while(p->next!=NULL) p=p->next;
    p->next=t;
}

void insertAfter(int val,int x) {
    Node* p=head;
    while(p!=NULL && p->data!=val) p=p->next;
    if(p!=NULL) {
        Node* t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

void insertBefore(int val,int x) {
    if(head==NULL) return;
    if(head->data==val){ insertBegin(x); return; }
    Node* p=head;
    while(p->next!=NULL && p->next->data!=val) p=p->next;
    if(p->next!=NULL) {
        Node* t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

void deleteBegin() {
    if(head==NULL) return;
    Node* t=head;
    head=head->next;
    delete t;
}

void deleteEnd() {
    if(head==NULL) return;
    if(head->next==NULL){ delete head; head=NULL; return; }
    Node* p=head;
    while(p->next->next!=NULL) p=p->next;
    delete p->next;
    p->next=NULL;
}

void deleteValue(int val) {
    if(head==NULL) return;
    if(head->data==val){ deleteBegin(); return; }
    Node* p=head;
    while(p->next!=NULL && p->next->data!=val) p=p->next;
    if(p->next!=NULL) {
        Node* t=p->next;
        p->next=p->next->next;
        delete t;
    }
}

void search(int val) {
    int pos=1;
    Node* p=head;
    while(p!=NULL) {
        if(p->data==val){ cout<<"Found at position "<<pos<<endl; return; }
        p=p->next; pos++;
    }
    cout<<"Not found"<<endl;
}

void display() {
    Node* p=head;
    while(p!=NULL){ cout<<p->data<<" "; p=p->next; }
    cout<<endl;
}

int main() {
    int ch,x,y;
    while(true) {
        cout<<"\n1.InsertBegin 2.InsertEnd 3.InsertAfter 4.InsertBefore";
        cout<<" 5.DeleteBegin 6.DeleteEnd 7.DeleteValue 8.Search 9.Display 10.Exit\n";
        cin>>ch;
        if(ch==1){cin>>x;insertBegin(x);}
        else if(ch==2){cin>>x;insertEnd(x);}
        else if(ch==3){cin>>y>>x;insertAfter(y,x);}
        else if(ch==4){cin>>y>>x;insertBefore(y,x);}
        else if(ch==5) deleteBegin();
        else if(ch==6) deleteEnd();
        else if(ch==7){cin>>x;deleteValue(x);}
        else if(ch==8){cin>>x;search(x);}
        else if(ch==9) display();
        else if(ch==10) break;
    }
}